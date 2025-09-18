# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:
        // Zombie(int _N, std::string _name);
        Zombie();
        void announce();
        std::string GetZombieName();
        ~Zombie();
    private:
        int N;
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif