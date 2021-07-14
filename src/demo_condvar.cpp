#include <iostream>
#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>
#include <queue>
#include <map>
#include <mutex>

std::condition_variable cond;
std::mutex mx;

void generate_events(std::queue<unsigned int>& q) {

    std::random_device rd{};
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<unsigned int> distrib{0, 25};

    for (;;) {

        auto value = distrib(generator);
        std::this_thread::sleep_for(std::chrono::seconds(value));

        std::cout << "[generator] Slept for " << value << " seconds" << std::endl;

        std::lock_guard<std::mutex> lock{mx};
        q.push(value);
        cond.notify_one();
        
    }
}

void process_events(std::queue<unsigned int>& q) {

    for (;;) {

        std::unique_lock<std::mutex> lock{mx};

        int count = 0;

        cond.wait(
            lock,
            [&q, &count]{
                
                std::cout << "[condvar] Checking " << ++count << std::endl;
                
                return !q.empty();
            }
        );

        auto value = q.front();
        q.pop();

        lock.unlock();

        std::cout << "[subscriber] Received " << value << std::endl;

    }

}

int main(int argc, char* argv[]) {

    std::queue<unsigned int> q;

    std::thread events_generator{generate_events, std::ref(q)};
    events_generator.detach();

    process_events(q);

    return 0;
}