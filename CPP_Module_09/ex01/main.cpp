#include "ReversePolishNotation.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    ReversePolishNotation   polish;
    polish.process_tokens(argv[1]);
    polish.calculator();
    return (0);
}