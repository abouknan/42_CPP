#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->Cat_Brain = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other)
{
    this->Cat_Brain = new Brain(*other.Cat_Brain);
    this->type = other.type;
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat& Cat::operator=(Cat const& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->Cat_Brain)
            delete this->Cat_Brain;
        this->Cat_Brain = new Brain(*other.Cat_Brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete this->Cat_Brain;
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea)
{
    if (this->Cat_Brain)
        this->Cat_Brain->setIdea(idx, idea);
}

const std::string& Cat::getIdea(int idx) const
{
    if (this->Cat_Brain)
        return this->Cat_Brain->getIdea(idx);
    static const std::string empty = "";
    return empty;
}