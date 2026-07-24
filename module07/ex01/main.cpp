#include <iostream>
#include "iter.hpp"

void printInt(const int &x) { std::cout << x << std::endl; }
void addOne(int &x) { x += 1; }

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Original array:" << std::endl;
    iter(arr, 5, printInt);

    iter(arr, 5, addOne);
    std::cout << "After addOne:" << std::endl;
    iter(arr, 5, printInt);

    const std::string strs[] = {"hello", "world"};
    iter(const_cast<std::string*>(strs), 2, [](std::string &s){ std::cout << s << std::endl; });

    return 0;
}
