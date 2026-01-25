#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute)
    : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const& other)
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm& AForm::operator=(AForm const& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
    this->executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName();
    if (form.getSigned())
        os << " (signed)";
    else
        os << " (not signed)";
    os << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
