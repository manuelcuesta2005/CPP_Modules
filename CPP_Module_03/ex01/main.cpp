#include "ScavTrap.hpp"

int main()
{
    ClapTrap a("wall-e");
    ClapTrap* bot = new ScavTrap("alfredo");
    ScavTrap b("simon");

    a.attack("a target");
    b.takeDamage(3);
    b.beRepaired(5);

    b.attack("a wall");
    b.guardGate();
    a.takeDamage(10);
    a.attack("nothing");

    bot->attack("intruder");
    delete bot;

    return 0;
}
