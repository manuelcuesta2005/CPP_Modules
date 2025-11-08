#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie New;
    New.name = name;
    New.announce();
}