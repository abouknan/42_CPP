#include "PhoneBook.hpp"
#include <iostream>

std::string get_arg(void)
{
    std::string cmd;

    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    if (std::getline(std::cin, cmd))
        return (cmd);
    return ("NULL");
}

int main ()
{
    std::string arg;

    while (1)
    {
        arg = get_arg();
        if (arg == "NULL")
            arg = "EXIT";
        if (arg == "ADD")
        {

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