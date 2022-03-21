#ifndef MATERIA_SOURCE
# define MATERIA_SOURCE

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		~MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		MateriaSource & operator=(const MateriaSource &src);
		void learnMateria(AMateria* src);
		AMateria* createMateria(std::string const & type);
};

#endif
