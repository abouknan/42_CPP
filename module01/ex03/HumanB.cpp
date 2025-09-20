#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string _name):weapon(NULL), name(_name){}

HumanB::~HumanB()
{
    return ;
}

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " 
    << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& wep)
{
    this->weapon = &wep;
}
