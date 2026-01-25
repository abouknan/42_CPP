#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
    try {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;
        
        std::cout << "Trying to increment grade (should throw exception)..." << std::endl;
        b1.increment();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Valid bureaucrat at lowest grade ===" << std::endl;
    try {
        Bureaucrat b2("Jane", 150);
        std::cout << b2 << std::endl;
        
        std::cout << "Trying to decrement grade (should throw exception)..." << std::endl;
        b2.decrement();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Invalid grade (too high) ===" << std::endl;
    try {
        Bureaucrat b3("Invalid", 0);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Invalid grade (too low) ===" << std::endl;
    try {
        Bureaucrat b4("Invalid", 151);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Valid increment/decrement ===" << std::endl;
    try {
        Bureaucrat b5("Bob", 75);
        std::cout << b5 << std::endl;
        
        b5.increment();
        std::cout << "After increment: " << b5 << std::endl;
        
        b5.decrement();
        std::cout << "After decrement: " << b5 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}