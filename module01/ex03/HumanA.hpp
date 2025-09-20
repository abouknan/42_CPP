# ifndef HUMANA_HPP
# define HUMANA_HPP

class Weapon;
#include <iostream>

class HumanA
{
    public:
        HumanA(std::string _name, Weapon& wep);
        ~HumanA();
        void attack();
    private:
        std::string name;
        Weapon& weapon;
};

#endif