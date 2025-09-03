#include <iostream>
#include <cctype>

int main (int ac, char **av)
{
    int a;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    else
    {
        for (a = 1; a < ac; a++)
        {
            for(int i = 0; av[a][i]; i++)
                std::cout << (char)toupper(av[a][i]);
        }
        std::cout << "\n";
    }
    return (0);
}
