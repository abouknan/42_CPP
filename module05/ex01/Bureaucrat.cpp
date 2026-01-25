#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade):name(_name), grade(_grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other): name(other.getName()), grade(other.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    if (this != &other)
    {
        this->grade = other.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName(void) const {return this->name;}
int Bureaucrat::getGrade(void) const {return this->grade;}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Bureaucrat::increment(void)
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrement(void)
{
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

Bureaucrat::~Bureaucrat() {}