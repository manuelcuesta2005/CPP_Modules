#include <iostream>

class Fixed {
    private:
        static const int    _fraccionalBits = 8;
        int _value;

    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
};