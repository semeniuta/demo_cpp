#include <cassert>
#include <iostream> // cout
#include <optional>
#include <vector> // vector
#include <cmath> // fabs
#include <algorithm> // sort
#include "fmt/base.h"
#include "helpers.h" // print_vector

std::optional<size_t> search_closest(const std::vector<double> & sorted_array, double x) {

    if (sorted_array.empty())
        return std::nullopt;

    const auto iter_geq = std::lower_bound(sorted_array.begin(), sorted_array.end(), x);

    if (iter_geq == sorted_array.begin())
        return 0;

    if (iter_geq == sorted_array.end())
        return sorted_array.size() - 1;

    const auto & a = *(iter_geq - 1);
    const auto & b = *(iter_geq);

    if (std::fabs(x - a) < std::fabs(x - b))
        return iter_geq - sorted_array.begin() - 1;

    return iter_geq - sorted_array.begin();
}

void test()
{
    const std::vector<double> many = {-2, 0, 1, 1.5, 3, 4.7};
    const std::vector<double> two = {1, 5};
    const std::vector<double> single = {10};
    const std::vector<double> empty = {};

    assert(std::nullopt == search_closest(empty, 20.0));

    assert(0 == search_closest(single, 20.0).value());
    assert(0 == search_closest(single, -1.0).value());

    assert(1 == search_closest(two, 20.0).value());
    assert(1 == search_closest(two, 4.0).value());
    assert(0 == search_closest(two, 2.0).value());
    assert(0 == search_closest(two, 0.5).value());

    assert(5 == search_closest(many, 20.0).value());
    assert(5 == search_closest(many, 4.0).value());
    assert(3 == search_closest(many, 2.0).value());
    assert(0 == search_closest(many, -10.0).value());
}

void example()
{
    // Define a vector of unsorted doubles
    std::vector<double> numbers = {3.14, 4.89, 1.2, 9.4, 0.57, -1.9, 5.3, 4.65};

    // Sort the vector
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted vector:" << std::endl; 
    print_vector(numbers);

    // Search for the closest
    for (double x : std::vector<double>{5, 5.1}) {
        fmt::print("\nSearching element closest to {}\n", x);

        if (const auto idx_closest = search_closest(numbers, x)) {
            fmt::print("Index of the closest element: {}\n", *idx_closest);
            fmt::print("The closest element itself: {:.2f}\n", numbers[*idx_closest]);
        } else {
            fmt::print("could not find\n");
        }
    }
}

int main()
{
    test();
    example();

    return 0;
}
