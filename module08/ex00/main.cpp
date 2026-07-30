#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "--- vector ---" << std::endl;
    try { std::cout << "Found: " << *easyfind(vec, 20) << std::endl; }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try { std::cout << "Found: " << *easyfind(vec, 99) << std::endl; }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    std::cout << "--- list ---" << std::endl;
    try { std::cout << "Found: " << *easyfind(lst, 15) << std::endl; }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }
    try { std::cout << "Found: " << *easyfind(lst, 99) << std::endl; }
    catch (std::exception &e) { std::cerr << e.what() << std::endl; }
}
