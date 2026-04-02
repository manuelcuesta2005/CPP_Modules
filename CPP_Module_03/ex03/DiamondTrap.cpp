#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    _name = name;
    _energyPoints = ScavTrap::_energyPoints;
    _hitPoints = FragTrap::_hitPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other) {
    std::cout << "copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy assigment called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
        _energyPoints = other._energyPoints;
        _hitPoints = other._hitPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << _name << " has been destroyed" << std::endl;
}

void DiamondTrap::WhoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
