#include "PhoneBook.hpp"

void print_contact(int index);
int is_valid(std::string input);

Phonebook::Phonebook(void): contacts_number(0)
{
    return ;
}

int Phonebook::addcontact(int index)
{
    std::string input;

    while (1)
    {
        print_contact(index);
        if (std::getline(std::cin, input))
        {
            if (is_valid(input))
                break;
            else
            {
                std::cout << "[PhoneBook] ⚠️ Invalid input. " 
                << "Only letters, digits and spaces are allowed." << std::endl;
                continue;
            }
        }
        else
            return (0);
    }
    return (1);
}

int Phonebook::contact_num(Phonebook st)
{
    return st.contacts_number;
}