#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal & src);
		WrongAnimal &	operator=(const WrongAnimal & src);
		void	makeSound(void) const;
		std::string	getType(void) const;
};

#endif
