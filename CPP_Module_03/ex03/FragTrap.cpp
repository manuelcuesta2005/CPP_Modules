#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
    std::cout << _name << " is the new design of FragTrap!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << _name << "copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    std::cout << "copy assigment called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _energyPoints = other._energyPoints;
        _hitPoints = other._hitPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << _name << " has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "Let's goo, give me five ✋​" << std::endl;
}