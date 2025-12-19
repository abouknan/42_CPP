#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
    if (this != &other)
    {
        // Delete old materias
        for (int i = 0; i < 4; i++)
        {
            if (materias[i])
            {
                delete materias[i];
                materias[i] = NULL;
            }
        }
        // Deep copy new materias
        for (int i = 0; i < 4; i++)
        {
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    
    for (int i = 0; i < 4; i++)
    {
        if (!materias[i])
        {
            materias[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    return NULL;
}
