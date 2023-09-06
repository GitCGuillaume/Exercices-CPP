#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << this->type << " AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	this->type = src.type;
}

AMateria & AMateria::operator=(AMateria const & src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
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
