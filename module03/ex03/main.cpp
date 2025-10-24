#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Creating DiamondTrap Ali ---" << std::endl;
    DiamondTrap d1("Ali"); // Parameterized constructor

    std::cout << "\n--- Testing whoAmI() ---" << std::endl;
    d1.whoAmI(); // Should print both DiamondTrap and ClapTrap names

    std::cout << "\n--- Testing attack() ---" << std::endl;
    d1.attack("KOKO"); // Uses ScavTrap's attack

    std::cout << "\n--- Testing takeDamage() ---" << std::endl;
    d1.takeDamage(5); // From ClapTrap

    std::cout << "\n--- Testing beRepaired() ---" << std::endl;
    d1.beRepaired(1); // From ClapTrap

    std::cout << "\n--- Testing another DiamondTrap ---" << std::endl;
    DiamondTrap d2; // Default constructor

    std::cout << "\n--- Assigning and Testing Copy ---" << std::endl;
    // d2 = d1; // If you implement operator=
    d2.whoAmI(); // Should show same names as d1 (if copied correctly)

    std::cout << "\n--- Exiting main() ---" << std::endl;
    return 0;
}
