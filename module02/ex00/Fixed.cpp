#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {setRawBits(0), std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->FixedInt = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->FixedInt = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->FixedInt;
}

void Fixed::setRawBits( int const raw )
{
    this->FixedInt = raw;
}
