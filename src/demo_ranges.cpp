#include <vector>
#include <iostream>
#include <ranges>
#include <numeric> // for std::iota

namespace {

constexpr size_t n_numbers = 10;

template <std::ranges::range Range>
void print_elements(Range v)
{
    for (auto element : v) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

} // namespace

int main()
{
    std::vector<int> numbers(n_numbers);
    std::iota(numbers.begin(), numbers.end(), 0);

    std::cout << "Original numbers:\n";
    print_elements(numbers);
    std::cout << "----------------------------\n";

    std::cout << "for_each example:\n";
    std::ranges::for_each(numbers, [](auto n) { std::cout << n << "\n"; });
    std::cout << "----------------------------\n";

    std::cout << "just even numbers:\n";
    auto view = numbers | std::ranges::views::filter([](int x) { return x % 2 == 0; });
    print_elements(view);
    std::cout << "----------------------------\n";

    return 0;
}
