#include "iter.hpp"

template <typename T>
void print(T& object) {
    std::cout << object << " ";
}

template <typename T>
void increment(T& value) {
    value++;
}

int main() {
    int array[] = { 1, 3, 7, 2, 8, 14 };
    size_t length = sizeof(array) / sizeof(array[0]);

    std::cout << "original array" << std::endl;
    ::iter(array, length, print<int>);
    std::cout << std::endl;

    std::cout << "increment array..." << std::endl;
    ::iter(array, length, increment<int>);
    std::cout << "New array: "; 
    ::iter(array, length, print<int>);
    std::cout << std::endl;
    return 0;
}