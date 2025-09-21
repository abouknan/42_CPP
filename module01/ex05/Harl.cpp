#include "Harl.hpp"

Harl::Harl(): function(NULL){}

Harl::~Harl() {}

void Harl::debug( void )
{
    std::cout << DEBUG_MSG << std::endl;
}

void Harl::info( void )
{
    std::cout << INFO_MSG << std::endl;
}

void Harl::warning( void )
{
    std::cout << WARNING_MSG << std::endl;
}

void Harl::error( void )
{
    std::cout << ERROR_MSG << std::endl;
}

int GetLevel(std::string level)
{
    if (level == "DEBUG") return 0;
    if (level == "INFO") return 1;
    if (level == "WARNING") return 2;
    if (level == "ERROR") return 3;
    return -1;
}

void Harl::complain(std::string level)
{
    int lvl;

    lvl = GetLevel(level);
    switch (lvl)
    {
        case 0:
            function = &Harl::debug;
            break;
        case 1:
            function = &Harl::info;
            break;
        case 2:
            function = &Harl::warning;
            break;
        case 3:
            function = &Harl::error;
            break;
        default:
            std::cout << RED << "Invalid level: " << RESET 
            << level << std::endl;
            return;
    }
    (this->*function)();
}