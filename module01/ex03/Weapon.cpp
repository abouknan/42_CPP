#include "Weapon.hpp"

const std::string& Weapon::getType(void) {return type;}

void Weapon::setType(std::string _type)
{
    this->type = _type;
}
Weapon::Weapon(std::string _type) {Weapon::setType(_type);}

Weapon::~Weapon()
{
    return ;
}