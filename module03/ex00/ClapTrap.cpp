#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("NoName"), HP(10), EP(10), AD(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string const _name): name(_name), HP(10), EP(10), AD(0)
{
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const& other)
{
    name = other.name;
    HP = other.HP;
    EP = other.EP;
    AD = other.AD;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->HP = other.HP;
        this->EP = other.EP;
        this->AD = other.AD;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HP <= 0 || this->EP <= 0)
        return ;
    this->EP--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
        << ", causing " << this->AD << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HP < amount || this->HP <= 0)
    {
        this->HP = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount 
          << " points of damage! HP is now " << this->HP << "." << std::endl;
        return ;
    }
    this->HP -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount 
          << " points of damage! HP is now " << this->HP << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HP <= 0 || this->EP <= 0)
        return ;
    this->HP += amount;
    this->EP--;
    std::cout << "ClapTrap " << this->name << " is repaired by " << amount 
          << " points! HP is now " << this->HP << " and EP is " << this->EP << "." << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called\n";
}
