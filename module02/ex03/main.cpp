#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(2.5f, 5);
    
    Point inside(2.5f, 2);
    Point outside(0, 5);
    Point onEdge(2.5f, 0);
    Point vertex(0, 0);
    
    std::cout << "Point inside triangle: " << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;
    std::cout << "Point outside triangle: " << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "YES" : "NO") << std::endl;
    std::cout << "Point a vertex: " << (bsp(a, b, c, vertex) ? "YES" : "NO") << std::endl;
    
    return 0;
}