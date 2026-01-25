#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;

    public:
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(AForm const& other);
        AForm& operator=(AForm const& other);
        virtual ~AForm();

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const& bureaucrat);
        void execute(Bureaucrat const& executor) const;
        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
