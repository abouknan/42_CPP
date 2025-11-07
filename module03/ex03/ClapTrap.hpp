#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const std::string& _name);
        ClapTrap(ClapTrap const& other);
        ClapTrap& operator=(ClapTrap const& other);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string name;
        unsigned int HP;
        unsigned int EP;
        unsigned int AD;
};


#endif