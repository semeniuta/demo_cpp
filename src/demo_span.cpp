#include <span>
#include <iostream>
#include <vector>

void print_span(std::span<int> s)
{
    for (int num : s) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> v = {0, 2, 8, 4, 3, 1, 25};

    const auto& ref = v;

    std::span<int> s{v};

    print_span(s);
    std::cout << s.data() << "\n";

    return 0;
}