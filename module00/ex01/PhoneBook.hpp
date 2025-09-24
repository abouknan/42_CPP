#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

enum Field
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Phonebook
{
    public:
        Phonebook();
        int addcontact(int index);
        int Get_Cn(void);
        void ShowContacts(void);
        void Increment_Contact(void);
        int getIndex(void);
        void print_field(int idx, int field);

    private:
        int     tail;
        int     contacts_number;
        Contact contacts[8];
};

#endif

