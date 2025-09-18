#include "Zombie.hpp"

int main (void)
{
    int N = 5;
    Zombie *zombie;

    zombie = zombieHorde(N, "Ali");
    if (!zombie)
        return 1;
    for (int i = 0; i < N; i++)
        zombie[i].announce();

    delete[] zombie;
}
