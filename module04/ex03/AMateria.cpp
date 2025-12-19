#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(AMateria const& other) : type(other.type)
{
}

AMateria& AMateria::operator=(AMateria const& other)
{
    if (this != &other)
    {
        // Type is not copied as per subject requirements
        (void)other;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
