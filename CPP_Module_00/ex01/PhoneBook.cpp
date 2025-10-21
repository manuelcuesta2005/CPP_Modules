#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() : id(0), count(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::intro()
{
    std::cout << "Welcome to Phonebook" << "\n";
    std::cout << "These are the options for interacting with the Phonebook" << "\n";
    std::cout << "1. ADD: create a new conctact" << "\n";
    std::cout << "2. SEARCH: find a contact by index" << "\n";
    std::cout << "3. EXIT: close the phonebook" << "\n";
}

void PhoneBook::ADD()
{
    book[id].setContact();
    id = (id + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::SEARCH()
{
    if (count == 0)
    {
        std::cout << "No contacts stored yet.\n";
        return;
    }
    std::cout << "+----------+----------+----------+----------+\n";
    std::cout << "|     Index| FirstName|  LastName|  NickName|\n";
    std::cout << "+----------+----------+----------+----------+\n";
    for (int i = 0; i < count; i++)
        book[i].showTable(i);
    std::cout << "+----------+----------+----------+----------+\n";
    int index;
    std::cout << "Enter index of the contact: ";
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= count)
    {
        std::cout << "Invalid index!\n";
        std::cin.clear();
        return;
    }
    book[index].getContact();
}

void PhoneBook::EXIT()
{
    std::cout << "Exit Phonebook....." << std::endl;
}
