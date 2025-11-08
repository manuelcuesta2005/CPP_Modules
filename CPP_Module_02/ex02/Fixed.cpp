#include "Fixed.hpp"

// Constructor original
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor Int 
Fixed::Fixed(const int number) {
    std::cout << "Int constructor called" << std::endl;
    _value = number * (1 << _fraccionalBits);
}

// Constructor Float
Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(number * (1 << _fraccionalBits));
}

// Constructor de Copia
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

// Boolean
bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// Aritmetic
Fixed Fixed::operator+(const Fixed& other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed& other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed& other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed& other) const { return Fixed(this->toFloat() / other.toFloat()); }

// increase - decrease
Fixed& Fixed::operator++() { 
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _value++;
    return (tmp);
}

Fixed& Fixed::operator--() {
    _value--;
    return (*this);
} 

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _value--;
    return (tmp);
}

// Min - Max
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl;
}