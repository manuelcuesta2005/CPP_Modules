#include <iostream>
#include <limits>
class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(const std::string& literal);
    bool isPseudo(const std::string type);
    bool isChar(const std::string type);
    bool isInt(const std::string type);
    bool isFloat(const std::string type);
    void printChar(const std::string type);
    void printInt(const std::string type);
    void printFloat(const std::string type);
    void printDouble(const std::string type);
};
