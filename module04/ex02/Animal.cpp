#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::Animal(Animal const& other)
{
    this->type = other.type;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal& Animal::operator=(Animal const& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Animal Copy Assignment Operator Called" << std::endl;
    return *this;
}

const std::string &Animal::getType() const
{
    return this->type;
}

void Animal::makeSound(void) const
{
    std::cout << "Generic animal sound" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}
