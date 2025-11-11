#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->Dog_Brain = new Brain();
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other)
{
    this->Dog_Brain = new Brain(*other.Dog_Brain);
    this->type = other.type;
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(Dog const& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->Dog_Brain)
            delete this->Dog_Brain;
        this->Dog_Brain = new Brain(*other.Dog_Brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete this->Dog_Brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea)
{
    if (this->Dog_Brain)
        this->Dog_Brain->setIdea(idx, idea);
}

const std::string& Dog::getIdea(int idx) const
{
    if (this->Dog_Brain)
        return this->Dog_Brain->getIdea(idx);
    static const std::string empty = "";
    return empty;
}