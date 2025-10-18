#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Hugo");
    a.attack("Victor");
    a.takeDamage(5);
    a.beRepaired(6);

    ClapTrap b(a);
    b.attack("Lorris");
    b.takeDamage(20);
    b.beRepaired(5);
}
