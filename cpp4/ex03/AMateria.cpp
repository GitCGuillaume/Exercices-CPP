#include "AMateria.hpp"

AMateria::AMateria()
{
	return ;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::setType(std::string name)
{
	this->type = name;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Materia used on " << target.getName() << std::endl;
}
