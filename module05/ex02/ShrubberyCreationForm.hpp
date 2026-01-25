#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const& other);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
        ~ShrubberyCreationForm();

        void executeAction() const;
};

#endif
