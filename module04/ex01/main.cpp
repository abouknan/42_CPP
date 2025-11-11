#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
       const Animal* j = new Dog();
       const Animal* i = new Cat();

       delete j;//should not create a leak
       delete i;
    }

    std::cout << "\n--- ex01 additional tests (array & deep copy) ---" << std::endl;

    // create array of Animals (half Dogs, half Cats)
    const int N = 6;
    Animal* zoo[N];
    for (int idx = 0; idx < N; ++idx)
    {
        if (idx < N/2)
            zoo[idx] = new Dog();
        else
            zoo[idx] = new Cat();
    }

    for (int idx = 0; idx < N; ++idx)
    {
        std::cout << "zoo[" << idx << "] type: " << zoo[idx]->getType() << std::endl;
        zoo[idx]->makeSound();
    }

    for (int idx = 0; idx < N; ++idx)
        delete zoo[idx];

    // deep copy test for Dog
    Dog* dog1 = new Dog();
    dog1->setIdea(0, "I love bones");
    Dog* dog2 = new Dog(*dog1); // copy ctor

    std::cout << "dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2->getIdea(0) << std::endl;

    dog1->setIdea(0, "I prefer cats now");
    std::cout << "after modifying dog1..." << std::endl;
    std::cout << "dog1 idea[0]: " << dog1->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2->getIdea(0) << std::endl;

    delete dog1;
    delete dog2;
    return 0;
}