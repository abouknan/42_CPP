#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    DiamondTrap d1("Ali");

    std::cout << "\n--- Testing whoAmI() ---" << std::endl;
    d1.whoAmI();

    std::cout << "\n--- Testing attack() ---" << std::endl;
    d1.attack("KOKO");

    std::cout << "\n--- Testing takeDamage() ---" << std::endl;
    d1.takeDamage(5);

    std::cout << "\n--- Testing beRepaired() ---" << std::endl;
    d1.beRepaired(1);

    std::cout << "\n--- Testing another DiamondTrap ---" << std::endl;
    DiamondTrap d2;

    std::cout << "\n--- Assigning and Testing Copy ---" << std::endl;
    d2 = d1;
    d2.whoAmI();

    std::cout << "\n--- Exiting main() ---" << std::endl;
    return 0;
}
