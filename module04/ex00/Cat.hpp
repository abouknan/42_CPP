#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const& other);
        Cat& operator=(Cat const& Cat);
        void makeSound(void) const;
        ~Cat();
};


#endif