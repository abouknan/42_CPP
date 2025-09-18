#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << "Zombie: " << name << " destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

std::string Zombie::GetZombieName(void)
{
    return name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}