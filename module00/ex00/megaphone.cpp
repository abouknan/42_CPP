#include <iostream>
#include <cctype>

int main (int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    else
    {
        for (int a = 1; a < ac; a++)
        {
            for(int i = 0; av[a][i]; i++)
                std::cout << (char)std::toupper(av[a][i]);
        }
        std::cout << "\n";
    }
    return (0);
}
