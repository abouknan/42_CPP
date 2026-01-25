#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const& other);
        PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
        ~PresidentialPardonForm();

        void executeAction() const;
};

#endif
