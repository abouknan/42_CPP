#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

enum FieldAction 
{
    GET,
    SET
};

enum Field
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Contact
{
    public:
        std::string field(int index, FieldAction action,
            const std::string input);

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

