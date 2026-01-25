#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute)
    : name(_name), isSigned(false), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(Form const& other)
    : name(other.name), isSigned(other.isSigned), 
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form& Form::operator=(Form const& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
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
