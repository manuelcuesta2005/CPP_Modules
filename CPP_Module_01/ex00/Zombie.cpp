#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Zombie constructor called" << std::endl;
}
Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
