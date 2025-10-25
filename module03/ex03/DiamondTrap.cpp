#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), name("Default")
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 30;
    
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name), name(_name)
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 30;

    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
}

void DiamondTrap::attack(std::string const target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    if (this->HP <= 0 || this->EP <= 0)
    {
        std::cout << "DiamondTrap " << this->name
                  << " cannot reveal its identity (no HP or EP left!)" << std::endl;
        return;
    }
    
    std::cout << "I am DiamondTrap " << this->name
              << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}
