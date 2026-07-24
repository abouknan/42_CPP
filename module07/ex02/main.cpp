#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> a(5);
    for (std::size_t i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i * 2);

    std::cout << "Array contents:" << std::endl;
    for (std::size_t i = 0; i < a.size(); ++i)
        std::cout << a[i] << std::endl;

    try {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Caught out-of-bounds access" << std::endl;
    }

    Array<int> b = a;
    b[0] = 42;
    std::cout << "After copy and modify, a[0] = " << a[0] << ", b[0] = " << b[0] << std::endl;

    return 0;
}
