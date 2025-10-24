#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
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


void DiamondTrap::attack(std::string target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    if (this->HP <= 0 || this->EP <= 0)
    {
        std::cout << "DiamondTrap Cannot Get the ClapTrap name because No EP or No HP " << std::endl;
        return ;
    }
    std::cout << "DiamondTrap I am " << this->name << " my ClapTrap name is " 
        << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}
