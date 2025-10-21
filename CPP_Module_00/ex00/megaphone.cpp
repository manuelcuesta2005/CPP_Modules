#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < strlen(argv[i]); j++)
			{
				char upper = toupper(argv[i][j]);
                std::cout << upper;
            }
        }
        
    } else {
        std::string message = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << message;
    }
    return (0);
}
