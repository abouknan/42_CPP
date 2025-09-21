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
    std::ofstream outputFile;

    if (ac != 4)
        return std::cout << RED << "Wrong Number of Args!!" << RESET << std::endl, 1;
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
    inputFile.close();
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string filename = av[1];
    size_t foundPos = 0;
    foundPos = line.find(s1, foundPos);
    if (foundPos == std::string::npos)
        return std::cout << RED << "Failed to find gived string" << RESET << std::endl, 1;
    while (1)
    {
        line.erase(foundPos, s1.length());
        line.insert(foundPos, s2);
        foundPos += s2.length();
        if ((foundPos = line.find(s1, foundPos)) == std::string::npos)
            break;
    }
    filename.append(".replace");
    outputFile.open(filename.c_str());
    if (!outputFile.is_open())
        return std::cerr << RED << "Error creating output file!" << RESET << std::endl, 1;
    outputFile << line;
    outputFile.close();
    std::cout << BLUE << "Replacement completed! Output: " 
    << filename << RESET << std::endl;
    return 0;
}