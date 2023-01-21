#include <vector>
#include <iostream>
#include <ranges>
#include <numeric> // for std::iota

namespace {

constexpr size_t n_numbers = 10;

template <typename T>
void print_vector(const std::vector<T>& v)
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

    print_vector(numbers);
}
