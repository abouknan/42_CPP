#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data d;
    d.value = 42;
    d.c = 'x';

    uintptr_t raw = Serializer::serialize(&d);
    Data* pd = Serializer::deserialize(raw);

    std::cout << "original address: " << &d << std::endl;
    std::cout << "raw value: " << raw << std::endl;
    std::cout << "deserialized address: " << pd << std::endl;
    std::cout << "deserialized->value: " << pd->value << std::endl;
    std::cout << "deserialized->c: " << pd->c << std::endl;

    if (pd == &d)
        std::cout << "Success: pointers match" << std::endl;
    else
        std::cout << "Failure: pointers differ" << std::endl;

    return 0;
}
