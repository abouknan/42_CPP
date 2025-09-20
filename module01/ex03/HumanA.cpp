#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string _name, Weapon& wep): name(_name), weapon(wep){}

HumanA::~HumanA()
{
    return ;
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " 
    << weapon.getType() << std::endl;
}
