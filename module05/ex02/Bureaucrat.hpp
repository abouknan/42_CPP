# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const& other);
        Bureaucrat& operator=(Bureaucrat const& other);
        ~Bureaucrat();

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
        int getGrade() const;
        void increment(void);
        void decrement(void);
        void signForm(AForm& form) const;
        void executeForm(AForm const& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif