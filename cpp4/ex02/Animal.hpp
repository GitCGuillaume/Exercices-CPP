#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string	type;

	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal & src);
		virtual Animal &	operator=(Animal const & src);
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
};

#endif
