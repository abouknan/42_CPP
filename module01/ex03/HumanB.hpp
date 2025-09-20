# ifndef HUMANB_HPP
# define HUMANB_HPP

class Weapon;
#include <iostream>

class HumanB
{
    public:
        HumanB(std::string _name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon& wep);
    private:
        Weapon* weapon;
        std::string name;
};

#endif