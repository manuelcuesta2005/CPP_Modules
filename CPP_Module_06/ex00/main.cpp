#include "ScalarConverter.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert_scalar <scalar_to_convert>\n"
			"Valid scalars to convert: int, float, double or char."
			<< std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    return(0);
}