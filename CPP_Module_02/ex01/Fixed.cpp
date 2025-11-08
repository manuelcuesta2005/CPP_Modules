#include "Fixed.hpp"

// Constructor original
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;
    _value = number * (1 << _fraccionalBits);
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(number * (1 << _fraccionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assigment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

int Fixed::toInt(void) const {
    return _value >> _fraccionalBits;
}

float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fraccionalBits);
}

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}