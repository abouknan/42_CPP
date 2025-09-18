#include "Weapon.hpp"

std::string& Weapon::getType(void)
{
    return type;
}

void Weapon::setType(std::string _type)
{
    this->type = _type;
}
Weapon::Weapon(std::string _type): type(_type){}

Weapon::~Weapon()
{
    return ;
}