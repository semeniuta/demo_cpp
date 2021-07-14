#include <iostream>
#include <thread>
#include <condition_variable>
#include <random>
#include <chrono>
#include <queue>

void generate_events() {

    std::random_device rd{};
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<unsigned int> distrib{0, 5};

    for (;;) {

        auto value = distrib(generator);
        std::this_thread::sleep_for(std::chrono::seconds(value));

        std::cout << "Slept for " << value << " seconds" << std::endl;
        
    }
}


int main(int argc, char* argv[]) {

    std::thread events_generator{generate_events};
    events_generator.join();

    return 0;
}