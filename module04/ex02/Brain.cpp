#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = std::string();
    std::cout << "Brain Default Constructor Called" << std::endl;
}

Brain::Brain(Brain const& other)
{
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain& Brain::operator=(Brain const& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain Copy Assignment Operator Called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea)
{
    if (idx < 0 || idx >= 100) return;
    ideas[idx] = idea;
}

const std::string& Brain::getIdea(int idx) const
{
    static const std::string empty = "";
    if (idx < 0 || idx >= 100) return empty;
    return ideas[idx];
}
