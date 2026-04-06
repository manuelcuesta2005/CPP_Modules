#include <iostream>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(const std::string& literal);
    static bool isPseudo(const std::string type);
    static bool isChar(const std::string type);
    static bool isInt(const std::string type);
    static bool isFloat(const std::string type);
    static void printConversion(double value, const std::string& literal);
};
