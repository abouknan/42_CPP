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
            for (int i = 0; i < 5; i++)
                (print_contact(i), std::getline(std::cin, arg));
            std::cout << arg << std::endl;
        }
        else if (arg == "SEARCH")
        {
        }
        else if (arg == "EXIT")
            break;
        else
            std::cout << "Wrong!" << std::endl;
    }
}