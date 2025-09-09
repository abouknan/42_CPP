#include "PhoneBook.hpp"

void print_contact(int index)
{
    switch (index)
    {
        case 0:
            std::cout << "first name: ";
            break;
        case 1:
            std::cout << "last name: ";
            break;
        case 2:
            std::cout << "nickname: ";
            break;
        case 3:
            std::cout << "phone number: ";
            break;
        case 4:
            std::cout << "darkest secret: ";
            break;
    }
    return ;
}

int is_valid(std::string arg)
{
    int res;

    res = 1;
    if (arg.empty())
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
            std::cout << "[Phonebook] 📇 Let's add a new contact!" << std::endl;
            for (int index = 0; index < 5; index++)
                if (!st.addcontact(index))
                    return(-1);
        }
        else if (arg == "SEARCH")
        {
            if (!st.contact_num(st))
                std::cout << "No contacts to search." << std::endl;
        }
        else if (arg == "EXIT")
            break;
        else
            std::cout << "Wrong!" << std::endl;
    }
}
