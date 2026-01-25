#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
    : AForm("ShrubberyCreationForm", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
    : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }

    file << "       ###\n";
    file << "      #o###\n";
    file << "    #####o###\n";
    file << "   #o#\\#|#/###\n";
    file << "    ###\\|/#o#\n";
    file << "     # }|{  #\n";
    file << "       }|{\n";
    file << "\n";
    file << "      ^^^^^\n";
    file << "     ^^^^^^^\n";
    file << "    ^^^^^^^^^\n";
    file << "   ^^^^^^^^^^^\n";
    file << "      | |\n";
    file << "      | |\n";
    file << "     ~~~~~~~\n";

    file.close();
    std::cout << "Shrubbery has been planted at " << this->target << std::endl;
}
