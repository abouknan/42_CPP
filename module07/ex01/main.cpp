#include <iostream>
#include "iter.hpp"

void printInt(const int &x) { std::cout << x << "\t"; }
void addOne(int &x) { x += 1; }
void printString(std::string &s) { std::cout << "String: " << s << std::endl; }

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Original array:" << std::endl;
    iter(arr, 5, printInt);
    std::cout << std::endl;

    iter(arr, 5, addOne);
    std::cout << "After addOne:" << std::endl;
    iter(arr, 5, printInt);
    std::cout << std::endl;

    const std::string strs[] = {"hello", "world"};
    iter(const_cast<std::string*>(strs), 2, printString);

    return 0;
}
