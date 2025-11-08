#include <iostream>
#include <cmath>

class Fixed {
    private:
        static const int    _fraccionalBits = 8;
        int _value;

    public:
        Fixed();
        Fixed(const int number);
        Fixed(const float number);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
