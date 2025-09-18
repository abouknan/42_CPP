# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string _type);
        std::string& getType(void);
        void setType(std::string _type);
        ~Weapon();
    private:
        std::string type;
};

#endif