#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& v) {
    
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]\n";
}

#endif