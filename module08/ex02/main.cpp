#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);

    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top after pop: " << mstack.top() << std::endl;

    std::cout << "elements: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
