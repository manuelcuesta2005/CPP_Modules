#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("wall-e");
    ClapTrap b("eva");

    a.attack("a target");
    b.takeDamage(3);
    b.beRepaired(5);

    b.attack("a wall");
    a.takeDamage(10);
    a.attack("nothing");

    return 0;
}
