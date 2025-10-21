#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook Contacts;
    std::string option;

    Contacts.intro();
    while (1) {
        std::cout << "enter any option: ";
        std::getline(std::cin, option);
        if (option == "ADD")
            Contacts.ADD();
        else if (option == "SEARCH")
            Contacts.SEARCH();
        else if (option == "EXIT") {
            Contacts.EXIT();
            break;
        }
        else
            std::cout << "Invalid Command to the phonebook" << std::endl;
    }
}
