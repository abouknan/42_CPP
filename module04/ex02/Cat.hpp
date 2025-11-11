#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(Cat const& other);
        Cat& operator=(Cat const& Cat);
        void makeSound(void) const;
        void setIdea(int idx, const std::string& idea);
        const std::string& getIdea(int idx) const;
        ~Cat();
    private:
        Brain* Cat_Brain;
};


#endif
