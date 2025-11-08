#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie* New = new Zombie();
    New->name = name;
    return New;
}