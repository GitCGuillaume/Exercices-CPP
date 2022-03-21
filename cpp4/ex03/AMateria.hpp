#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class	AMateria
{
	private:
		std::string		type;

	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria(void);
		virtual std::string const & getType() const;
		virtual void setType(std::string name);
		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
