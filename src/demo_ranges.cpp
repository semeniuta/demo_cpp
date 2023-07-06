#include <vector>
#include <iostream>
#include <ranges>
#include <numeric> // for std::iota
#include <sstream>
#include <iomanip> // for std::hex
#include <fmt/core.h>

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

std::string int_to_hex(int number)
{
    std::stringstream ss;
    ss << "0x" << std::hex << number;
    return ss.str();
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
    auto view_even = numbers | std::views::filter([](int x) { return x % 2 == 0; });
    print_elements(view_even);
    std::cout << "----------------------------\n";

    std::cout << "more transformation of even numbers:\n";
    auto view_even_times_100_as_hex = numbers
        | std::views::filter([](int x) { return x % 2 == 0; })
        | std::views::transform([](int x) { return x * 100; })
        | std::views::transform(int_to_hex);
    print_elements(view_even_times_100_as_hex);
    std::cout << "----------------------------\n";

    std::cout << "ranges::transform with vector.reserve\n";
    std::vector<std::string> users;
    users.reserve(numbers.size());
    std::ranges::transform(
        numbers,
        std::back_inserter(users),
        [](int n) { return fmt::format("user_{}", n); }
    );
    print_elements(users);
    std::cout << "----------------------------\n";

    std::cout << "ranges::count_if\n";
    std::vector<float> scores = {0.2, 0.68, 0.31, 0.59, 0.81, 0.74, 0.14};
    const auto is_high = [](float score) { return score >= 0.5f; };
    auto n_high = std::ranges::count_if(scores, is_high);
    std::cout << "number of scores >= 0.5: " << n_high << "\n";
    print_elements(scores | std::views::filter(is_high));
    std::cout << "----------------------------\n";

    std::cout << "view to vector\n";
    auto view_int_to_hex = std::views::iota(0, 21) | std::views::transform(int_to_hex);

    std::vector<std::string> hex_strings;
    hex_strings.reserve(view_int_to_hex.size());
    std::ranges::copy(view_int_to_hex, std::back_inserter(hex_strings));

    print_elements(hex_strings);

    return 0;
}
