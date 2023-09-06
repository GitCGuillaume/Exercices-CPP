#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	protected:
		AMateria*	store_materia[4];

	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria* src) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
