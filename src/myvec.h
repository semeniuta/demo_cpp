#ifndef MYVEC_H
#define MYVEC_H

//#include <stddef.h> // for size_t
#include <iostream>

const int DEFAULT_VECTOR_CAPACITY = 5;

template <typename T> 
void copy_data(T* src, T* dst, size_t sz) {

    for (size_t i = 0; i < sz; i++) {
        dst[i] = src[i];
    }

}

template <typename T>
class MyVec {

public:
  
    // Default constructor + constructor based on the initial capacity
    MyVec(unsigned int cap=DEFAULT_VECTOR_CAPACITY) : capacity_{cap}, size_{0} {
      
      elem_ = new T[capacity_];  
      
      std::cout << "Construction completed (default/capacity)\n";

    }

    // Destructor
    ~MyVec() {
        
        delete[] elem_;
        
        std::cout << "Destruction completed (" << elem_ << ")\n";
        
    }

    // Copy constructor
    MyVec(const MyVec& other) {

        copy_construct(other);

        std::cout << "Construction completed (copy)\n";

    }

    // Move constructor
    MyVec(MyVec&& other) {

        move_construct(std::move(other));

        std::cout << "Construction completed (move)\n";

    }

    // Copy assignment
    MyVec& operator=(const MyVec& other) {

        delete[] elem_;
        copy_construct(other);

        std::cout << "Copy assignment completed\n";

        return *this;

    }

    // Move assignment
    MyVec& operator=(MyVec&& other) {

        delete[] elem_;
        move_construct(std::move(other));

        std::cout << "Move assignment completed\n";

        return *this;

    }

    void push_back(T val) {

        size_t next_size = size_ + 1;

        if (next_size == capacity_ + 1) {

            capacity_ *= 2;
            
            T* resized = new T[capacity_];
            copy_data(elem_, resized, size_);

            delete[] elem_;

            std::cout << "Vector resized. Old address: " << elem_;
            std::cout << ". New address: " << resized << "\n";

            elem_ = resized;
        }

        elem_[size_] = val;
        size_++;

    }

    void print_vector() {

        std::cout << "Vector at " << elem_ << ". Size: " << size_ << ", capacity: " << capacity_ << "\n";

        std::cout << "[";
        
        for (size_t i = 0; i < size_; i++) {
            
            std::cout << elem_[i];

            if (i < size_ - 1) {
                std::cout  << ", ";
            }
        }

        std::cout << "]\n";

    }


private:

    T* elem_;
    size_t capacity_;
    size_t size_;

    void copy_construct(const MyVec& other) {

        elem_ = new T[other.capacity_];  
        size_ = other.size_;
        capacity_ = other.capacity_;

        copy_data(other.elem_, elem_, size_);
    }

    void move_construct(MyVec&& other) {

        copy_construct(other);

        other.elem_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

};

#endif