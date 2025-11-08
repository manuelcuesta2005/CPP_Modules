#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
    std::cout << _name << " is the new design of ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << _name << " copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "copy assigment called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _energyPoints = other._energyPoints;
        _hitPoints = other._hitPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << _name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << _name << " is too tired or died to attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << _name << " slashes fiercely at " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << _name << " is now in Gate keeper mode! 🛡️" << std::endl;
}