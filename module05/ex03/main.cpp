#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Test 1: Intern creates valid forms ===" << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
    }

    std::cout << "\n=== Test 2: Create all three form types ===" << std::endl;
    {
        Intern intern;
        AForm* forms[3];
        
        forms[0] = intern.makeForm("shrubbery creation", "home");
        forms[1] = intern.makeForm("robotomy request", "Target");
        forms[2] = intern.makeForm("presidential pardon", "Criminal");
        
        for (int i = 0; i < 3; i++)
        {
            if (forms[i])
            {
                std::cout << *forms[i] << std::endl;
                delete forms[i];
            }
        }
    }

    std::cout << "\n=== Test 3: Invalid form name ===" << std::endl;
    {
        Intern intern;
        AForm* invalid;
        
        invalid = intern.makeForm("coffee making", "office");
        if (invalid == NULL)
            std::cout << "Form creation failed as expected" << std::endl;
    }

    std::cout << "\n=== Test 4: Complete workflow with intern ===" << std::endl;
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Arthur Dent");
        
        if (form)
        {
            std::cout << boss << std::endl;
            std::cout << *form << std::endl;
            
            boss.signForm(*form);
            boss.executeForm(*form);
            
            delete form;
        }
    }

    std::cout << "\n=== Test 5: Multiple interns ===" << std::endl;
    {
        Intern intern1;
        Intern intern2;
        Bureaucrat worker("Worker", 50);
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "garden");
        AForm* form2 = intern2.makeForm("robotomy request", "Robot");
        
        if (form1)
        {
            worker.signForm(*form1);
            worker.executeForm(*form1);
            delete form1;
        }
        
        if (form2)
        {
            worker.signForm(*form2);
            worker.executeForm(*form2);
            delete form2;
        }
    }

    std::cout << "\n=== Test 6: Case sensitivity test ===" << std::endl;
    {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("Robotomy Request", "Test");
        if (form == NULL)
            std::cout << "Case matters - form name must be exact" << std::endl;
            
        form = intern.makeForm("robotomy request", "Test");
        if (form)
        {
            std::cout << "Correct case works: " << form->getName() << std::endl;
            delete form;
        }
    }

    std::cout << "\n=== Test 7: Memory management ===" << std::endl;
    {
        Intern intern;
        
        for (int i = 0; i < 3; i++)
        {
            AForm* temp = intern.makeForm("shrubbery creation", "temp");
            if (temp)
            {
                std::cout << "Created form #" << i + 1 << std::endl;
                delete temp;
            }
        }
        std::cout << "All forms properly deleted" << std::endl;
    }

    return 0;
}
