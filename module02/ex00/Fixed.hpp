# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();
    private:
        int FixedInt;
        static const int FractionalBits;
};

#endif