#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(Brain const& other);
        Brain& operator=(Brain const& other);
        ~Brain();
        void setIdea(int idx, const std::string& idea);
        const std::string& getIdea(int idx) const;
    private:
        std::string ideas[100];
};


#endif
