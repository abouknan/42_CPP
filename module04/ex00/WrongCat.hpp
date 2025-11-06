#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat& operator=(const WrongCat& other);
        ~WrongCat();
        void makeSound() const;
        WrongCat(const WrongCat& other);
};

#endif
