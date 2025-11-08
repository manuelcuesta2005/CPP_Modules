#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage) : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage) {
    std::cout << "New Design ClapTrap created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << _name << "copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "copy assigment called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << _name << " has no energy left to attack (possibly died)" << std::endl;
        return ;
    }
    std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    if (_hitPoints <= 0) {
        _hitPoints = 0;
        std::cout << _name << " has died" << std::endl;
    }
    std::cout << _name << " takes " << amount << " points of damage! HP left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints <= 0) {
        std::cout << _name << "has no energy left to repair" << std::endl;
        return ;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << _name << " repairs itself, gaining " << amount << " hit points! HP: " << _hitPoints << ", Energy: " << _energyPoints << std::endl;
}