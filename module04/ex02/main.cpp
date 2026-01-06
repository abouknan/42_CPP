#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n--- Array test (half Dogs, half Cats) ---" << std::endl;

    const int N = 4;
    Animal* animals[N];

    for (int idx = 0; idx < N/2; idx++)
        animals[idx] = new Dog();

    for (int idx = N/2; idx < N; idx++)
        animals[idx] = new Cat();

    for (int idx = 0; idx < N; idx++)
        delete animals[idx];

    return 0;
}