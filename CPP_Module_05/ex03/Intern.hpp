#include <iostream>
#include <stdexcept>
#include <exception>

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        void makeForm();
};
