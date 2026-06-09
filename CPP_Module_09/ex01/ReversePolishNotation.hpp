#ifndef REVERSE_POLISH_NOTATION_HPP
#define REVERSE_POLISH_NOTATION_HPP

#include <iostream>
#include <stack>
#include <vector>

class ReversePolishNotation
{
    private:
        std::stack<int>                 _stack;
        std::vector<char>        _tokens;
    public:
        ReversePolishNotation();
        ReversePolishNotation(const ReversePolishNotation& other);
        ReversePolishNotation& operator=(const ReversePolishNotation& other);
        ~ReversePolishNotation();

        void    process_tokens(const std::string chain);
        bool    isOperator(const char sign);
        void    calculator(void);
};

#endif