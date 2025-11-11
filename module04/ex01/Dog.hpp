#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(Dog const& other);
        Dog& operator=(Dog const& Dog);
        void makeSound(void) const;
        void setIdea(int idx, const std::string& idea);
        const std::string& getIdea(int idx) const;
        ~Dog();
    private:
        Brain* Dog_Brain;
};


#endif