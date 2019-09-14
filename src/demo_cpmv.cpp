/*
 *
 * Demo of copy and move operations based on the MyVec class (myvec.h)
 * 
 * vec0 --(copy)--> vec1
 * vec0 --(copy)--> vec2 --(move)--> vec3 --(move)--> vec4
 * 
 */

#include "myvec.h"
#include <iostream>

int main() {

    std::cout << "Creating vec0\n";
    MyVec<int> vec0;
    for (unsigned int i = 0; i < 12; i++) {
        vec0.push_back(i);
    }    
    vec0.print_vector();
    std::cout << "\n";

    std::cout << "Creating vec1 (copy-constructed from vec0)\n";
    MyVec<int> vec1{vec0};
    vec1.print_vector();
    std::cout << "\n";

    std::cout << "Creating vec2 (copy-assignment from vec0)\n";
    MyVec<int> vec2{};
    vec2 = vec0;
    vec2.print_vector();
    std::cout << "\n";

    std::cout << "Creating vec3 (move-constructed from vec2)\n";
    MyVec<int> vec3{ std::move(vec2) };
    std::cout << "Now vec2 (moved-from):\n"; 
    vec2.print_vector();
    std::cout << "Now vec3:\n";
    vec3.print_vector();
    std::cout << "\n";

    std::cout << "Creating vec4 (move-assigned from vec3)\n";
    MyVec<int> vec4{};
    vec4 = std::move(vec3);
    std::cout << "Now vec3 (moved-from):\n"; 
    vec3.print_vector();
    std::cout << "Now vec4:\n";
    vec4.print_vector();
    std::cout << "\n";

    return 0;
}