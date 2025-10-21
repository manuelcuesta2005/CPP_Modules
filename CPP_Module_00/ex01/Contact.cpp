#include "Contact.hpp"
#include <iomanip>

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setContact()
{
    do {
        std::cout << "Enter the First Name: ";
        std::getline(std::cin, FirstName);
        if (FirstName.empty())
            std::cout << "Field cannot be empty.\n";
    } while (FirstName.empty());
    do {
        std::cout << "Enter the Last Name: ";
        std::getline(std::cin, LastName);
        if (LastName.empty())
            std::cout << "Field cannot be empty.\n";
    } while (LastName.empty());
    do {
        std::cout << "Enter the NickName: ";
        std::getline(std::cin, NickName);
        if (NickName.empty())
            std::cout << "Field cannot be empty.\n";
    } while (NickName.empty());
    do {
        std::cout << "Enter the Phone Number: ";
        std::getline(std::cin, PhoneNumber);
        if (PhoneNumber.empty())
            std::cout << "Field cannot be empty.\n";
    } while (PhoneNumber.empty());
    do {
        std::cout << "Enter the Darkest Secret: ";
        std::getline(std::cin, DarkestSecret);
        if (DarkestSecret.empty())
            std::cout << "Field cannot be empty.\n";
    } while (DarkestSecret.empty());
    std::cout << "Created contact successfully\n";
}

void Contact::showTable(int index)
{
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << truncate(FirstName)
              << "|" << std::setw(10) << truncate(LastName)
              << "|" << std::setw(10) << truncate(NickName)
              << "|\n";
}

void Contact::getContact()
{
    std::cout << "First Name: " << FirstName << std::endl;
    std::cout << "Last Name: " << LastName << std::endl;
    std::cout << "NickName: " << NickName << std::endl;
    std::cout << "PhoneNumber: " << PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << DarkestSecret << std::endl;
}

std::string Contact::truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}