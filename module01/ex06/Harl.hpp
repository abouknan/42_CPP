#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define RED     "\033[31m"
#define RESET   "\033[0m"

#define	DEBUG_MSG "[ DEBUG ]\nI love having extra bacon for my 7XL-double- \
cheese-triple-pickle-special-ketchup burger.\nI really do!"
#define	INFO_MSG "[ INFO ]\nI cannot believe adding extra bacon costs more \
money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be \
asking for more!"
#define	WARNING_MSG "[ WARNING ]\nI think I deserve to have some extra bacon for \
free.\nI’ve been coming for years, whereas you started working here since last \
month."
#define	ERROR_MSG "[ ERROR ]\nThis is unacceptable! I want to speak to the manager \
now."
#define DEF_MSG "[ Probably complaining about insignificant problems ]"

class Harl
{
    public:
        Harl(int ac, char **av);
        ~Harl();
        void complain( int level );
        int Checkargs(int ac, std::string arg);
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif