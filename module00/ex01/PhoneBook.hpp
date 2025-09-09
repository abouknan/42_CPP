#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

class Contact
{
    public:
        void setfields(int index, std::string input);

    private:
        std::string fields[5];
};

class Phonebook
{
    public:
        Phonebook();
        int addcontact(int index);
        int contact_num(void);

    private:
        int     tail;
        int     contacts_number;
        Contact contacts[8];
};

#endif

