#include <iostream>

class Base {
    public:
        Base();
        Base(const Base& other);
        Base& operator=(const Base& other);
        virtual ~Base();
}