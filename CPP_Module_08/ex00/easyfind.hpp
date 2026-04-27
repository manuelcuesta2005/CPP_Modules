#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::runtime_error {
    public:
        NotFoundException(const std::string message) : std::runtime_error(message) { }
};

template <typename T>
typename T::iterator easyfind(T& array, int number)
{
    typename T::iterator found = std::find(array.begin(), array.end(), number);
    if (found == array.end())
        throw NotFoundException("Error al encontrar el numero");
    return found;
}