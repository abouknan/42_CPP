#include <iostream>
#include <iomanip>

#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "         Adresses           " << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "str:       " <<  YELLOW << &str << RESET << std::endl;
    std::cout << "stringPTR: " << YELLOW << stringPTR << RESET << std::endl;
    std::cout << "stringREF: " << YELLOW << &stringREF << RESET <<std::endl;
    std::cout << std::setw(30) << std::setfill(' ') << std::endl;
    std::cout << std::setw(30) << std::setfill(' ') << std::endl;

    std::cout << "          Values                " << std::endl;
    std::cout << "----------------------------" << std::endl;
    std::cout << "str:       " << BLUE <<  str << RESET << std::endl;
    std::cout << "stringPTR: " << BLUE << *stringPTR << RESET << std::endl;
    std::cout << "stringREF: " << BLUE << stringREF << RESET << std::endl;
}