#include <iostream>

class list
{
    public:
        int a;
        std::string str;
        list(){a = 1, str = "Ali Bouknana";}
        list(int s, std::string ptr){a = s, str = ptr;}
};

int main ()
{
    list obj;
    list obj1(2, "Aya Achy");

    std::cout << obj.a << "\t" << obj.str <<std::endl;
    std::cout << obj1.a << "\t" << obj1.str <<std::endl;
}