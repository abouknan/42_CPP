#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(Dog const& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof! Woof!" << std::endl;
}