#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        Intern(Intern const& other);
        Intern& operator=(Intern const& other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target);

    private:
        AForm* createShrubbery(std::string target);
        AForm* createRobotomy(std::string target);
        AForm* createPardon(std::string target);
};

#endif
