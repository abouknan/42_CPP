#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed area = ((a.getX() * (b.getY() - c.getY())) + 
                  (b.getX() * (c.getY() - a.getY())) + 
                  (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
    return (area < 0) ? area * Fixed(-1) : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed mainArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    
    return (area1 + area2 + area3 == mainArea && 
            area1 > 0 && area2 > 0 && area3 > 0);
}