#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    if (this != &other)
        *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    if (this == &other)
        return *this;
    return *this;
}

ScalarConverter::~ScalarConverter() { }

bool ScalarConverter::isPseudo(const std::string type) {
    return (type == "nan" || type == "nanf" ||
            type == "+inf" || type == "+inff" ||
            type == "-inf" || type == "-inff" ||
            type == "inf" || type == "inff");
}

bool ScalarConverter::isChar(const std::string type) {
    return (type.length() == 1 && !isdigit(type[0]));
}

bool ScalarConverter::isInt(const std::string type) {
    
}

