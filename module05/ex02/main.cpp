#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat gardener("Gardener", 140);
        ShrubberyCreationForm shrub("home");
        
        std::cout << gardener << std::endl;
        std::cout << shrub << std::endl;
        
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat surgeon("Surgeon", 40);
        RobotomyRequestForm robotomy("Bender");
        
        std::cout << surgeon << std::endl;
        std::cout << robotomy << std::endl;
        
        surgeon.signForm(robotomy);
        surgeon.executeForm(robotomy);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Execute without signing ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm unsignedForm("office");
        
        std::cout << unsignedForm << std::endl;
        boss.executeForm(unsignedForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << intern << std::endl;
        std::cout << pardon << std::endl;
        
        intern.signForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat highRank("HighRank", 10);
        Bureaucrat lowRank("LowRank", 100);
        PresidentialPardonForm pardon("Prisoner");
        
        std::cout << highRank << std::endl;
        std::cout << lowRank << std::endl;
        std::cout << pardon << std::endl;
        
        highRank.signForm(pardon);
        std::cout << pardon << std::endl;
        
        lowRank.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Multiple forms execution ===" << std::endl;
    try {
        Bureaucrat superBoss("SuperBoss", 1);
        
        ShrubberyCreationForm shrub1("garden");
        ShrubberyCreationForm shrub2("park");
        RobotomyRequestForm robot("Target1");
        PresidentialPardonForm pardon("VIP");
        
        superBoss.signForm(shrub1);
        superBoss.signForm(shrub2);
        superBoss.signForm(robot);
        superBoss.signForm(pardon);
        
        superBoss.executeForm(shrub1);
        superBoss.executeForm(shrub2);
        superBoss.executeForm(robot);
        superBoss.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Borderline grades ===" << std::endl;
    try {
        Bureaucrat exact145("Exact145", 145);
        Bureaucrat exact137("Exact137", 137);
        ShrubberyCreationForm shrub("test");
        
        std::cout << exact145 << std::endl;
        std::cout << exact137 << std::endl;
        
        exact145.signForm(shrub);
        exact137.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
