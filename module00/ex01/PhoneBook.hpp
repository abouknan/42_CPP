#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class Contact
{
    public:

    private:
        std::string fields[5];
};

class Phonebook
{
    public:
        void addcontact(int index);

    private:
        Contact contacts[8];
};

#endif
