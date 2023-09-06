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
		AMateria(AMateria const & src);
		virtual ~AMateria();
		virtual	AMateria & operator=(AMateria const & src);
		virtual std::string const & getType() const;
		virtual void setType(std::string name);
		virtual	AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
