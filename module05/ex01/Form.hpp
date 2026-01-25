#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

    public:
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(Form const& other);
        Form& operator=(Form const& other);
        ~Form();

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
