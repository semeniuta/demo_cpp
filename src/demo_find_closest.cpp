#include <iostream> // cout
#include <vector> // vector
#include <math.h> // fabs
#include <algorithm> // sort
#include "helpers.h" // print_vector

// used in meshy
// https://github.com/semeniuta/meshy/blob/master/src/shapedist.cpp
long search_closest(const std::vector<double>& sorted_array, double val) {

    auto iter_geq = std::lower_bound(sorted_array.begin(), sorted_array.end(), val);

    if (iter_geq == sorted_array.begin()) {
        return 0;
    }

    double a = *(iter_geq - 1);
    double b = *(iter_geq);

    if (fabs(val - a) < fabs(val - b)) {
        return iter_geq - sorted_array.begin() - 1;
    }

    return iter_geq - sorted_array.begin();

}

int main() {

    std::vector<double> numbers = {3.14, 4.89, 1.2, 9.4, 0.57, -1.9, 5.3, 4.65};

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted vector:" << std::endl; 
    print_vector(numbers);

    for (double x : std::vector<double>{5, 5.1}) {

        std::cout << "\nSearching element closest to " << x << std::endl;

        long idx_closest = search_closest(numbers, x);

        std::cout << "Index of the closest element: " << idx_closest << std::endl;
        std::cout << "The closest element itself: " << numbers[idx_closest] << std::endl;
    }

    return 0;

}