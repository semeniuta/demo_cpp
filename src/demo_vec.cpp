#include "myvec.h"
#include <iostream>

int main() {

    MyVec<int> vec;

    for (unsigned int i = 0; i < 25; i++) {
        vec.push_back(i);
        vec.print_vector();
    }

    return 0;
}