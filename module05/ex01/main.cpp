#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Test 1: Create valid forms ===" << std::endl;
    try {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
        
        Form form2("Permission Slip", 100, 75);
        std::cout << form2 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Invalid form grades ===" << std::endl;
    try {
        Form invalidForm1("Invalid", 0, 50);
    }
    catch (std::exception& e) {
        std::cout << "Exception creating form with grade 0: " << e.what() << std::endl;
    }
    
    try {
        Form invalidForm2("Invalid", 50, 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception creating form with grade 151: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Successful form signing ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", 50, 25);
        
        std::cout << boss << std::endl;
        std::cout << contract << std::endl;
        
        boss.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Failed form signing (grade too low) ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form importantDoc("Top Secret", 25, 5);
        
        std::cout << intern << std::endl;
        std::cout << importantDoc << std::endl;
        
        intern.signForm(importantDoc);
        std::cout << importantDoc << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Borderline cases ===" << std::endl;
    try {
        Bureaucrat mid("MidLevel", 50);
        Form exactForm("Exact Match", 50, 50);
        
        std::cout << mid << std::endl;
        std::cout << exactForm << std::endl;
        
        mid.signForm(exactForm);
        std::cout << exactForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Multiple signing attempts ===" << std::endl;
    try {
        Bureaucrat high("HighRank", 10);
        Form memo("Memo", 20, 15);
        
        std::cout << memo << std::endl;
        high.signForm(memo);
        std::cout << "Trying to sign again..." << std::endl;
        high.signForm(memo);
        std::cout << memo << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Grade exactly at threshold ===" << std::endl;
    try {
        Bureaucrat worker("Worker", 75);
        Form permit("Permit", 76, 50);
        
        std::cout << worker << std::endl;
        std::cout << permit << std::endl;
        
        worker.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}