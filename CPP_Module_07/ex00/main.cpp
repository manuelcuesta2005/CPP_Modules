#include <iostream>
#include "whatever.hpp"

int main() {
    int a = 8;
    int b = 3;

    ::swap(a, b);
    std::cout << "Template test #1 (swap, min & max to int value)" << std::endl;
    std::cout << "new A: " << a << std::endl;
    std::cout << "new B: " << b << std::endl;
    std::cout << "Min: " << ::min(a, b) << std::endl;
    std::cout << "Max: " << ::max(a, b) << std::endl;

    std::string chain1 = "hola a todos";
    std::string chain2 = "keloke menores";

    ::swap(chain1, chain2);
    std::cout << "Template test #2 (swap, min & max to string values)" << std::endl;
    std::cout << "new chain1: " << chain1 << std::endl;
    std::cout << "new chain2: " << chain2 << std::endl;
    std::cout << "Min: " << ::min(chain1, chain2) << std::endl;
    std::cout << "Max: " << ::max(chain1, chain2) << std::endl;

    float number1 = 3.124534f;
    float number2 = 6.143522f;
    ::swap(number1, number2);
    std::cout << "Template test #3 (swap, min & max to float value)" << std::endl;
    std::cout << "new number1: " << number1 << std::endl;
    std::cout << "new number2: " << number2 << std::endl;
    std::cout << "Min: " << ::min(number2, number1) << std::endl;
    std::cout << "Max: " << ::max(number2, number1) << std::endl;

    return 0;
}