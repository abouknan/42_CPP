#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(Cat const& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! Meow!" << std::endl;
}