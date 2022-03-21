#include "Character.hpp"

Character::Character(std::string name) : ICharacter()
{
	for (unsigned int i = 0; i < 4; i++)
		this->materia[i] = NULL;
	return ;
}

Character::Character(std::string name) : ICharacter()
{
	std::cout << "Constructor Character called." << std::endl;
	this->_name = name;
	for (unsigned int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

Character::~Character()
{
	for (unsigned int i = 0; i < 4; i++)
		if (this->materia[i] != NULL)
			delete this->materia[i];
	std::cout << "Destructor Character called." << std::endl;
}

Character::Character(const Character & src)
{
	int	i = 0;

	std::cout << "Copy character called" << std::endl;
	this->_name = src.getName();
	for (i = 0; i < 4; i++)
		this->materia[i] = NULL;
	for (i = 0; i < 4; i++)
	{
		if (src.materia[i])
			this->materia[i] = src.materia[i]->clone();
	}
}

Character &	Character::operator=(const Character & src)
{
	int i = 0;

	std::cout << "Assignation character called" << std::endl;
	this->_name = src.getName();
	for (i = 0; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
		this->materia[i] = NULL;
	}
	for (i = 0; i < 4; i++)
	{
		if (src.materia[i])
			this->materia[i] = src.materia[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	unsigned int	i = 0;

	if (m != NULL)
	{
		while (i < 4 && this->materia[i] != NULL)
		{
			i++;
		}
		if (3 >= i && this->materia[i] == NULL)
		{
			this->materia[i] = m;
			std::cout << this->getName() << " is equipping "
				<< this->materia[i]->getType() << " materia." << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->materia[idx] != NULL)
	{
		std::cout << this->getName() << " is unequipping "
			<< this->materia[idx]->getType() << std::endl;
		this->materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->materia[idx])
		this->materia[idx]->use(target);
}
