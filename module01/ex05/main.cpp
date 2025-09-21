#include "Harl.hpp"

int main(void)
{
    Harl karen;

    std::cout << "=== Testing all complaint levels ===" << std::endl;
    
    karen.complain("DEBUG");
    std::cout << std::endl;
    
    karen.complain("INFO");
    std::cout << std::endl;
    
    karen.complain("WARNING");
    std::cout << std::endl;
    
    karen.complain("ERROR");
    std::cout << std::endl;

    std::cout << "=== Testing invalid levels ===" << std::endl;
    karen.complain("INVALID");
    karen.complain("debug");
    karen.complain("");
    karen.complain("RANDOM");
        
    std::cout << std::endl << "=== Harl complaining a lot ===" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        karen.complain("DEBUG");
        karen.complain("WARNING");
        karen.complain("ERROR");
        std::cout << "--- Complaint round " << (i + 1) << " ---" << std::endl;
    }
    
    return 0;
}