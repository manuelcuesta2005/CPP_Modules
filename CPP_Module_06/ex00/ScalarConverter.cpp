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

void ScalarConverter::convert(const std::string& literal) {
    double value;
    if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    } else {
        char* endptr;
        value = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
            if (!isPseudo(literal)) {
                std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
                return;
            }
        }
    }
    printConversion(value, literal);
}

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
    if (type.empty()) return false;
    size_t i = (type[0] == '-' || type[0] == '+') ? 1 : 0;
    if (i == type.length()) return false;
    for (; i < type.length(); i++) {
        if (!std::isdigit(type[i])) return false;
    }
    return true;
}

void ScalarConverter::printConversion(double value, const std::string& literal) {
    std::cout << "char: ";
    if (isPseudo(literal) || value < 0 || value > 127) 
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (isPseudo(literal) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}