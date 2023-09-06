#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string name);
		virtual ~Animal();
		Animal(const Animal & src);
		virtual Animal &	operator=(Animal const & src);
		virtual void	makeSound(void) const;
		virtual std::string	getType(void) const;
};

#endif
