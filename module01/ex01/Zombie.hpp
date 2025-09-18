#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie();
        void setName(std::string name);
        void announce();
        std::string GetZombieName();
        ~Zombie();
    private:
        std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif