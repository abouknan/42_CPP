#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "Testing generate / identify (pointer):" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        Base* p = generate();
        identify(p);
        delete p;
    }

    std::cout << "\nTesting identify (reference):" << std::endl;
    A a; B b; C c;
    identify(a);
    identify(b);
    identify(c);

    return 0;
}
