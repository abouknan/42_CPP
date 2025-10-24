#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("Ali");
    a.whoAmI();
    a.attack("KOKO");
    a.takeDamage(5);
    a.beRepaired(1);
}
