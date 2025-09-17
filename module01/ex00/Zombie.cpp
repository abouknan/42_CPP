#include "Zombie.hpp"

std::string Zombie::GetZombieName(void)
{
    return Zombie::name;
}

void Zombie::announce(void)
{
    std::cout << GetZombieName() << ": ";
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string _name): name(_name)
{
    return ;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: " << GetZombieName() << " destroyed" << std::endl;
}