#include "PhoneBook.hpp"

void print_contact(Field f);
int is_valid(int index, std::string input);

std::string Contact::field(int index, FieldAction action, const std::string input = "")
{
    if (action == SET)
        return this->fields[index] = input, "";
    else if (action == GET)
        return this->fields[index];
    return "";
}


Phonebook::Phonebook(void): tail(0), contacts_number(0)
{
    return ;
}

int Phonebook::addcontact(int index)
{
    std::string input;

    while (1)
    {
        print_contact((Field)index);
        if (std::getline(std::cin, input))
        {
            if (is_valid(index, input))
            {
                this->contacts[this->tail].field(index, SET, input);
                break;
            }
            else
            {
                if (index == 3)
                {
                    std::cout << RED << "[PhoneBook] ❌ Invalid phone number. Digits only." 
                    << RESET << std::endl;
                    continue;
                }
                std::cout << RED <<"[PhoneBook] ⚠️ Invalid input. "
                << "Only letters, digits and spaces are allowed."<< RESET << std::endl;
                continue;
            }
        }
        else
            return (0);
    }
    this->tail = (this->tail + 1) % 8;
    return (1);
}

int Phonebook::contact_num(void)
{
    return this->contacts_number;
}
