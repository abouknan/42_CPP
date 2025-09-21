#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define RED     "\033[31m"
#define RESET   "\033[0m"

#define	DEBUG_MSG "[DEBUG]\nI love having extra bacon for my 7XL-double- \
cheese-triple pickle-specialketchup burger. I really do!"
#define	INFO_MSG "[INFO]\nI cannot believe adding extra bacon costs more \
money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be \
asking for more!"
#define	WARNING_MSG "[WARNING]\nI think I deserve to have some extra bacon for \
free. I’ve been coming for years, whereas you started working here just last \
month."
#define	ERROR_MSG "[ERROR]\nThis is unacceptable! I want to speak to the manager \
now."

class Harl
{
    public:
        void (Harl::*function)(void);
        Harl();
        ~Harl();
        void complain( std::string level );
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
};

#endif