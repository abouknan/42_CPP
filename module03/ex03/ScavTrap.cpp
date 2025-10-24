#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("unknown")
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 20;

    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const& _name) : ClapTrap(_name)
{
    this->HP = 100;
    this->EP = 50;
    this->AD = 20;

    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& other): ClapTrap(other.name)
{
    HP = other.HP;
    EP = other.EP;
    AD = other.AD;
    
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HP <= 0)
    {
        std::cout << "ScavTrap " << name 
            << " can’t attack because it has no hit points left!" << std::endl;
        return;
    }
    if (EP <= 0)
    {
        std::cout << "ScavTrap " << name 
            << " can’t attack because it has no energy points left!" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "ScavTrap " << this->name << " attacks " << target 
        << ", causing " << this->AD << " points of damage!" << std::endl;
}


void ScavTrap::guardGate()
{
    if (this->HP <= 0 || this->EP <= 0)
    {
        std::cout << "ScavTrap: " << this->name 
            << " cannot enter Gate keeper mode!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->name 
        << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";
}
