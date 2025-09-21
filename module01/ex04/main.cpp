#include <iostream>
#include <fstream>

#define BLUE    "\033[34m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

int main (int ac, char **av)
{
    std::string tmp;
    std::string line;
    std::ifstream inputFile;

    if (ac != 4)
        return 1;
    inputFile.open(av[1]);
    if (!inputFile.is_open())
        return  std::cerr << RED << "Error opening file!" << RESET << std::endl, 1;
    if (!std::getline(inputFile, line))
        return 1;
    while (1)
    {
        line.append(tmp);
        if (!std::getline(inputFile, tmp))
            break;
        line += "\n";
    }
    size_t foundPos = line.find(av[2]);
    if (foundPos == std::string::npos)
        return std::cout << RED << "The word '" << av[2] 
        << "' was not found." << RESET << std::endl, 1;
    while (1)
    {
        /* code */
    }
    
    std::cout << foundPos << std::endl;
    // std::cout << line << std::endl;
    inputFile.close();
}