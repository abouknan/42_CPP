#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), name("Default")
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 30;
    
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name  + "_clap_name"), name(_name)
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 30;

    std::cout << "DiamondTrap Parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other)
{
    *this = other;
    std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    std::cout << "DiamondTrap assignment operator called\n";
    return *this;
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
