#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("unknown")
{
    this->HP = 100;
    this->EP = 100;
    this->AD = 30;

    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const& _name) : ClapTrap(_name)
{
    this->HP = 100;
    this->EP = 100;
    this->AD = 30;

    std::cout << "FragTrap Parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other): ClapTrap(other.name)
{
    HP = other.HP;
    EP = other.EP;
    AD = other.AD;
    
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        std::cout << "FragTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (HP <= 0)
    {
        std::cout << "FragTrap " << name 
            << " can’t attack because it has no hit points left!" << std::endl;
        return;
    }
    if (EP <= 0)
    {
        std::cout << "FragTrap " << name 
            << " can’t attack because it has no energy points left!" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "FragTrap " << this->name << " attacks " << target 
        << ", causing " << this->AD << " points of damage!" << std::endl;
}


FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";
}

void	FragTrap::highFivesGuys(void) 
{
	if (this->HP <= 0 || this->EP <= 0)
	{
		std::cout << "FragTrap: " << this->name 
            << " cannot request high fives!" << std::endl;
		return ;
	}
	std::cout << "FragTrap: " << this->name 
        << " requests a positive high five!" << std::endl;
}