#include <iostream>
#include <string>
#include <vector>

struct person {
    std::string name;
    unsigned int age;
    std::vector<int> numbers; // TODO make a demo with this vector
};

void print_string_addr(const std::string& s) {
    
    auto name_addr = static_cast<const void *>(s.data());
    std::cout << name_addr << "\n";
}

void inspect_person(const person& p) {

    if (p.name.empty()) {
        std::cout << "<empty>";
    } else {
        std::cout << p.name;
    }

    std::cout << " " << p.age << "\n";
    print_string_addr(p.name);
}

int main() {


    person me{"Alex", 29, {4, 8, 16}};

    std::cout << "me (before move):\n";
    inspect_person(me);
    std::cout << "\n";
    
    person me_moved;
    me_moved = std::move(me);

    std::cout << "me (after move):\n";
    inspect_person(me);
    std::cout << "\n";

    std::cout << "me_moved:\n";
    inspect_person(me_moved);
    std::cout << "\n";

    return 0;
}