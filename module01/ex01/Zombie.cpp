#include "Zombie.hpp"

Zombie::Zombie(int _N, std::string _name): N(_N), name(_name)  
{
}

Zombie::~Zombie()
{
    return ;
}

std::string Zombie::GetZombieName(void)
{
    return name;
}

void Zombie::announce(void)
{
    std::cout << "Zombie: " << name << "Hello!";
}