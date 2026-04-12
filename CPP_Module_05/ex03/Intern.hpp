#include <iostream>
#include <stdexcept>
#include <exception>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        AForm* makeForm(const std::string& name, const std::string& target);

        class UnknownForm : public std::runtime_error {
            public:
                UnknownForm(const std::string& message);
        };
};
