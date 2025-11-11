#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(Animal const& other);
        Animal& operator=(Animal const& Animal);
        const std::string& getType() const;
        virtual void makeSound(void) const = 0; // abstract
        virtual ~Animal();
    protected:
        std::string type;
};


#endif
