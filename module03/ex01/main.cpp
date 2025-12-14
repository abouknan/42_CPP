#include "ScavTrap.hpp"

int main(void)
{
    {
        ClapTrap b("Jack");
        b.attack("Lorris");
        b.takeDamage(2);
        b.beRepaired(5);
    }

    std::cout << std::endl << std::endl;

    {
        ScavTrap a("Hugo");
        a.attack("Victor");
        a.takeDamage(5);
        a.beRepaired(6);
        a.guardGate();
    }
}
