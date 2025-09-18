#include "Zombie.hpp"

int main (void)
{
    int N = 5;
    Zombie *zombie;

    zombie = zombieHorde(N, "Ali");
    for (int i = 0; i < N; i++)
        zombie->announce();
}
