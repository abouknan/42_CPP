#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(Animal const& other);
        Animal& operator=(Animal const& Animal);
        const std::string& getType() const;
        virtual void makeSound(void) const;
        virtual ~Animal();
    protected:
        std::string type;
};


#endif