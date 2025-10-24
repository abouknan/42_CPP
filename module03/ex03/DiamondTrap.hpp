#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(std::string _name);
        DiamondTrap(DiamondTrap const& other);
        DiamondTrap& operator=(DiamondTrap const& other);
        ~DiamondTrap();
        void whoAmI();
        void attack(std::string target);
    private:
        std::string name;
};

#endif