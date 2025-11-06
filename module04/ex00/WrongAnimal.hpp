#ifndef	WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &other);
		virtual	~WrongAnimal(void);
		WrongAnimal&	operator=(WrongAnimal const &other);
		std::string		getType(void) const;
		void	makeSound(void) const;
	protected:
		std::string	type;
};

#endif