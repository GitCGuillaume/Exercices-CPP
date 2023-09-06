#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(std::string name);
		virtual ~Cat();
		Cat(const Cat & src);
		Cat & operator=(Cat const & src);
		void	makeSound(void) const;
		Brain *	getBrain() const;
};

#endif
