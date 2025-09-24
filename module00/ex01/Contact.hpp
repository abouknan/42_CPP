#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

enum FieldAction 
{
    GET,
    SET
};

class Contact
{
    public:
        std::string field(int index, FieldAction action,
            const std::string input);
    private:
        std::string fields[5];
};


#endif