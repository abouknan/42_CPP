#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed()
{
    setRawBits(0);
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : FixedInt(value << FractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : FixedInt(roundf(value * (1 << FractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->FixedInt = fixed.FixedInt;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits( int const raw )
{
    this->FixedInt = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)this->FixedInt / (1 << FractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->FixedInt >> FractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}