#include "PhoneBook.hpp"

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
        }
        else if (arg == "SEARCH")
        {
            if (!st.contact_num())
                std::cout << YELLOW << "[PhoneBook] 📂 No contacts available. Try adding one with ADD."
                << RESET << std::endl;
        }
        else if (arg == "EXIT")
            break;
        else
            std::cout << RED << "[PhoneBook] ❌ Unknown command! Try again with ADD, SEARCH or EXIT." 
            << RESET << std::endl;
    }
}
