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
        Phonebook();
        int addcontact(int index);
        int contact_num(Phonebook st);

    private:
        // int     index;
        int     contacts_number;
        Contact contacts[8];
};

#endif

