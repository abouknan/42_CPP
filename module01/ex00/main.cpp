#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("Ali");
    zombie->announce();
    delete zombie;
    
    randomChump("Bob");
    return 0;
}