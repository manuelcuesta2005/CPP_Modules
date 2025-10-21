#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
    private:
        int     id;
        int     count;
        Contact book[8];
    
    public:
        PhoneBook();
        ~PhoneBook();
    
        void    intro();
        void    ADD();
        void    SEARCH();
        void    EXIT();
};
