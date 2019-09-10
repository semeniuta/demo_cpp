#include <iostream>
#include <string>
#include <vector>

struct person {
    std::string name;
    unsigned int age;
    std::vector<int> numbers; 
};

void inspect_x(const person& p) {

    std::cout << "name=";

    if (p.name.empty()) {
        std::cout << "<empty>";
    } else {
        std::cout << p.name;
    }

    std::cout << " age=";
    std::cout << " " << p.age;

    std::cout << " numbers=";
    if (p.numbers.data() == nullptr) {
        std::cout << "NULL";
    } else {
        std::cout << "[";
        for (int i = 0; i < p.numbers.size() - 1; i++)
        {
            std::cout << p.numbers[i] << ", ";
        }
        std::cout << p.numbers[p.numbers.size() - 1] << "]";
    }
    std::cout << "\n";

    std::cout << "Address of .name:\t" << static_cast<const void *>(p.name.data()) << "\n";

    std::cout << "Address of .numbers:\t" << static_cast<const void *>(p.numbers.data()) << "\n";

    std::cout << "\n";
}

int main() {

    person x{"Alex", 29, {4, 8, 16}};

    std::cout << "me (before move):\n";
    inspect_x(x);

    person x_moved;
    x_moved = std::move(x);

    std::cout << "x (after move):\n";
    inspect_x(x);

    std::cout << "x_moved:\n";
    inspect_x(x_moved);

    return 0;
}