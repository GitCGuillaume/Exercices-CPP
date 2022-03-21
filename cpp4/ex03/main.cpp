#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

void	copy_source_materia(MateriaSource const & src)
{
	std::cout << "COPY MATERIA SOURCE TEST" << std::endl;
	MateriaSource cpy(src);
	std::cout << "ASSIGNATION TEST" << std::endl;
	cpy = src;
	std::cout << "END MATERIA SOURCE COPY" << std::endl;
	return ;
}

void	copy_character(Character const & src)
{
	std::cout << "COPY CHARACTER TEST" << std::endl;
	Character cpy(src);
	std::cout << "ASSIGNATION TEST" << std::endl;
	cpy = src;
	std::cout << "Copy name = " << cpy.getName() << std::endl;
	std::cout << "END CHARACTER COPY" << std::endl;
	return ;
}

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria*	tmp = NULL;
	AMateria*	tmp_unequip = NULL;
	ICharacter*	me = new Character("me");

	std::cout << "Character name : " << me->getName() << std::endl;
	
	tmp = src->createMateria("ice");
	if (tmp)
		std::cout << "Materia name : " << tmp->getType() << std::endl;
	me->equip(tmp);

	tmp_unequip = src->createMateria("cure");
	if (tmp_unequip)
	{
		std::cout << "tmp_unequip Materia name : " << tmp_unequip->getType() << std::endl;
		me->equip(tmp_unequip);
		me->unequip(1);
	}
	tmp = src->createMateria("qsd");
	if (tmp)
	{
		std::cout << "Materia name : " << tmp->getType() << std::endl;
		me->equip(tmp);
	}
	tmp = src->createMateria("ice");
	if (tmp)
	{
		std::cout << "Materia name : " << tmp->getType() << std::endl;
		me->equip(tmp);
	}
	tmp = src->createMateria("ice");
	if (tmp)
	{
		std::cout << "Materia name : " << tmp->getType() << std::endl;
		me->equip(tmp);
	}
	tmp = src->createMateria("cure");
	if (tmp)
	{
		std::cout << "Materia name : " << tmp->getType() << std::endl;
		me->equip(tmp);
	}
	me->use(0, *me);
	me->use(1, *me);
	me->use(2, *me);
	me->use(3, *me);

	std::cout << std::endl << std::endl;
	copy_source_materia(dynamic_cast<MateriaSource&>(*src));
	std::cout << std::endl << std::endl;
	copy_character(dynamic_cast<Character&>(*me));
	std::cout << std::endl << std::endl;
	delete me;
	if (tmp_unequip)
		delete tmp_unequip;
	delete src;
	return (0);
}
