#include "PhoneBook.hpp"

int Phonebook::getIndex(void)
{
    std::string input;
    int index;

    while (1)
    {
        std::cout << YELLOW << "[PhoneBook] 🔍 Enter the index for more info: ";
        if (!std::getline(std::cin, input))
            return -1;
        std::cout << RESET;
        size_t start = input.find_first_not_of(" \t\n\r\f\v");
        size_t end = input.find_last_not_of(" \t\n\r\f\v");
        if (start == std::string::npos)
            continue;
        input = input.substr(start, end - start + 1);
        try
        {
            index = std::stoi(input);
        }
        catch (...)
        {
            std::cout << RED <<"[PhoneBook] ❌ Please enter a valid number!" 
            << RESET <<std::endl;
            continue;
        }
        if (index < 0 || index >= this->Get_Cn())
        {
            std::cout << RED << "[PhoneBook] ⚠️ Index out of range." 
            << RESET << std::endl;
            continue;
        }
        return index;
    }
}


void print_contact(Field f)
{
    switch (f)
    {
        case FIRST_NAME:
            std::cout << "first name: ";
            break;
        case LAST_NAME:
            std::cout << "last name: ";
            break;
        case NICKNAME:
            std::cout << "nickname: ";
            break;
        case PHONE_NUMBER:
            std::cout << "phone number: ";
            break;
        case DARKEST_SECRET:
            std::cout << "darkest secret: ";
            break;
    }
    return ;
}

void Phonebook::print_field(int idx, int field)
{
    std::string arg;

    arg = this->contacts[idx].field(field, GET, "");
    std::cout << arg << std::endl;
}

int is_valid(int index, std::string arg)
{
    int res;

    res = 1;
    if (arg.empty())
        return (0);
    if (index == 3)
        for (size_t i = 0; i < arg.size(); i++)
            if (!std::isdigit(arg[i]))
                return (0);
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (!std::isalnum(arg[i]) && !std::isspace(arg[i]))
        {
            res = 0;
            break;
        }
    }
    return (res);
}

std::string get_arg(void)
{
    std::string cmd;

    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    if (std::getline(std::cin, cmd))
        return (cmd);
    return ("NULL");
}

int main (void)
{
    Phonebook   st;
    std::string arg;

    while (1)
    {
        arg = get_arg();
        if (arg == "NULL")
            arg = "EXIT";
        if (arg == "ADD")
        {
            std::cout << BLUE << "[Phonebook] 📇 Let's add a new contact!" << RESET << std::endl;
            for (int index = 0; index < 5; index++)
                if (!st.addcontact(index))
                    return(-1);
            st.Increment_Contact();
        }
        else if (arg == "SEARCH")
        {
            if (!st.Get_Cn())
                std::cout << YELLOW << "[PhoneBook] 📂 No contacts available. Try adding one with ADD."
                << RESET << std::endl;
            else
            {
                int index;

                st.ShowContacts();
                index = st.getIndex();
                for (int i = 0; i < 5 ; i++)
                    (print_contact((Field)i),st.print_field(index, i));
            }
        }
        else if (arg == "EXIT")
            break;
        else
            std::cout << RED << "[PhoneBook] ❌ Unknown command! Try again with ADD, SEARCH or EXIT." 
            << RESET << std::endl;
    }
}
