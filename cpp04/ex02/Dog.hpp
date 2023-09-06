#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(std::string name);
		virtual ~Dog();
		Dog(const Dog & src);
		Dog & operator=(Dog const & src);
		void	makeSound(void) const;
		Brain *	getBrain() const;
};

#endif
