#include "Fixed.hpp"

const int Fixed::FractionalBits = 8;

Fixed::Fixed() {setRawBits(0);}

Fixed::Fixed(const int value) : FixedInt(value << FractionalBits) {}

Fixed::Fixed(const float value) : FixedInt(roundf(value * (1 << FractionalBits))) {}

Fixed::Fixed(const Fixed& fixed) : FixedInt(fixed.FixedInt) {}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    if (this != &fixed)
        this->FixedInt = fixed.FixedInt;
    return *this;
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed& other) const
{
    return this->FixedInt > other.FixedInt;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->FixedInt < other.FixedInt;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->FixedInt >= other.FixedInt;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->FixedInt <= other.FixedInt;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->FixedInt == other.FixedInt;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->FixedInt != other.FixedInt;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->FixedInt + other.FixedInt);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->FixedInt - other.FixedInt);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->FixedInt * other.FixedInt) >> FractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->FixedInt << FractionalBits) / other.FixedInt);
    return result;
}

Fixed& Fixed::operator++()
{
    this->FixedInt++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->FixedInt++;
    return temp;
}

Fixed& Fixed::operator--()
{
    this->FixedInt--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->FixedInt--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

int Fixed::getRawBits(void) const
{
    return this->FixedInt;
}

void Fixed::setRawBits(int const raw)
{
    this->FixedInt = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->FixedInt / (1 << FractionalBits);
}

int Fixed::toInt(void) const
{
    return this->FixedInt >> FractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}