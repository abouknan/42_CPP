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
void Phonebook::Increment_Contact(void)
{
    this->tail = (this->tail + 1) % 8;
    if (this->contacts_number < 8)
        this->contacts_number++;
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
            return (std::cout << "\n", 0);
    }
    return (1);
}

int Phonebook::Get_Cn(void)
{
    return this->contacts_number;
}

void Phonebook::ShowContacts(void)
{
    std::cout << BLUE << "[PhoneBook] 📇 Your contacts: " << RESET << std::endl;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < Get_Cn(); i++)
    {
        std::cout << std::setw(10) << i << "|";
        for (int field = 0; field < 3; field++)
        {
            std::string input = this->contacts[i].field(field, GET);
            if (input.size() > 10)
                input = input.substr(0, 9) + ".";
            std::cout << std::setw(10) << input;
            if (field != 2)
                std::cout << "|";
        }
        std::cout << std::endl;
    }
}

