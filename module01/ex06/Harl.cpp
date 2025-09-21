#include "Harl.hpp"

Harl::Harl(int ac, char **av) 
{
    if (ac == 1)
        return ;
    complain(Checkargs(ac, av[1]));
}

Harl::~Harl() {}

void Harl::debug( void )
{
    std::cout << DEBUG_MSG << std::endl << std::endl;
}

void Harl::info( void )
{
    std::cout << INFO_MSG << std::endl << std::endl;
}

void Harl::warning( void )
{
    std::cout << WARNING_MSG << std::endl << std::endl;
}

void Harl::error( void )
{
    std::cout << ERROR_MSG << std::endl << std::endl;
}

int Harl::Checkargs(int ac, std::string arg)
{
    if (ac != 2)
        return (-1);
    if (arg == "DEBUG") return 0;
    if (arg == "INFO") return 1;
    if (arg == "WARNING") return 2;
    if (arg == "ERROR") return 3;
    return -1;
}

void Harl::complain( int level )
{
    switch (level)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << DEF_MSG << std::endl;
    }
    return ;
}