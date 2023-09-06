#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource created" << std::endl;
	for (int i = 0; 4 > i; i++)
		this->store_materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; 4 > i; i++)
	{
		if (this->store_materia[i])
			delete this->store_materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	int	i = 0;

	std::cout << "MateriaSource copy" << std::endl;
	for (i = 0; i < 4; i++)
		this->store_materia[i] = NULL;
	for (i = 0; i < 4; i++)
	{
		if (src.store_materia[i])
			this->store_materia[i] = src.store_materia[i]->clone();
	}
}

MateriaSource &	MateriaSource::operator=(const MateriaSource &src)
{
	int	i = 0;

	std::cout << "Assignation MateriaSource called" << std::endl;
	for (i = 0; i < 4; i++)
	{
		if (this->store_materia[i])
			delete this->store_materia[i];
		this->store_materia[i] = NULL;
	}
	for (i = 0; i < 4; i++)
	{
		if (src.store_materia[i])
			this->store_materia[i] = src.store_materia[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* src)
{
	int	i = 0;

	while (i < 4)
	{
		if (this->store_materia[i] == NULL)
		{
			this->store_materia[i] = src;
			break;
		}
		i++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria	*materia = NULL;
	int		result;

	result = type.compare(std::string("ice"));
	if (result == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->store_materia[i])
			{
				if (this->store_materia[i]->getType().compare(type) == 0)
				{
					materia = new Ice();
					materia->setType(type);
					return (materia);
				}
			}
		}
	}
	result = type.compare(std::string("cure"));
	if (result == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->store_materia[i])
			{
				if (this->store_materia[i]->getType().compare(type) == 0)
				{
					materia = new Cure();
					materia->setType(type);
					return (materia);
				}
			}
		}
	}
	return (NULL);
}
