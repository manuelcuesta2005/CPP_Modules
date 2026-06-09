#include "ReversePolishNotation.hpp"

ReversePolishNotation::ReversePolishNotation() { }

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation& other) { 
    *this = other;
}

ReversePolishNotation& ReversePolishNotation::operator=(const ReversePolishNotation& other) { 
    if (this != &other) {
        this->_stack = other._stack;
        this->_tokens = other._tokens;
    }
    return (*this);
}

ReversePolishNotation::~ReversePolishNotation() { }

bool    ReversePolishNotation::isOperator(const char sign) {
    return (sign == '+' || sign == '-' || sign == '*' || sign == '/');
}

void    ReversePolishNotation::process_tokens(const std::string chain) {
    for (size_t i = 0; i < chain.length(); i++) {
        if (chain[i] == ' ')
            continue;
        else if (isdigit(chain[i]) && (chain[i + 1] == ' ' || chain[i + 1] == '\0'))
            _tokens.push_back(chain[i]);
        else if (isOperator(chain[i]))
            _tokens.push_back(chain[i]);
        else {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
}

void    ReversePolishNotation::calculator(void) {
    for (size_t i = 0; i < _tokens.size(); i++) {
        if (isdigit(_tokens[i])) {
            _stack.push(_tokens[i] - '0');
        }
        else if (isOperator(_tokens[i])) {
            if (_stack.size() >= 2) {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                if (_tokens[i] == '/' && b == 0) {
                    std::cerr << "Error" << std::endl;
                    return ;
                } else {
                    switch (_tokens[i])
                    {
                        case '+':
                            _stack.push(a + b);
                            break;
                        case '-':
                            _stack.push(b - a);
                            break;
                        case '*':
                            _stack.push(a * b);
                            break;
                        case '/':
                            _stack.push(b / a);
                            break;
                        default:
                            break;
                    }
                }
            } else {
                std::cerr << "Error" << std::endl;
            }
        }
    }
    if (_stack.size() == 1) {
        std::cout << _stack.top() << std::endl;
    } else {
        std::cerr << "Error inesperado!!" << std::endl;
    }
}
