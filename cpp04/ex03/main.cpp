#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

void	copySourceMateria(MateriaSource const & src)
{
	std::cout << "COPY MATERIA SOURCE TEST" << std::endl;
	MateriaSource cpy(src);
	std::cout << "ASSIGNATION TEST" << std::endl;
	cpy = src;
	std::cout << "END MATERIA SOURCE COPY" << std::endl;
	return ;
}

void	copyCharacter()
{
	Character	src("CPY");
	IMateriaSource	*ms = new MateriaSource();
	AMateria*	cure = NULL;
	AMateria*	ice = NULL;

	ms->learnMateria(new Ice());
	ms->learnMateria(new Cure());
	cure = ms->createMateria("cure");
	if (cure)
	{
		std::cout << "Materia name : " << cure->getType() << std::endl;
		src.equip(cure);
	}
	ice = ms->createMateria("ice");
	std::cout << "COPY CHARACTER TEST" << std::endl;
	Character cpy(src);
	std::cout << "Copy name = " << cpy.getName() << std::endl;
	src.unequip(0);
	if (ice)
	{
		std::cout << "Materia name : " << ice->getType() << std::endl;
		src.equip(ice);
	}
	src.use(0, cpy);
	cpy.use(0, src);
	delete cure;
	//delete ice;
	delete ms;
	std::cout << "END CHARACTER COPY" << std::endl;
	return ;
}

void	equipMateria(IMateriaSource	**src, ICharacter**	me)
{
	AMateria*	tmp = NULL;

	if (src && me && *src && *me)
	{
		tmp = (*src)->createMateria("qsd");
		if (tmp)
		{
			std::cout << "Materia name : " << tmp->getType() << std::endl;
			(*me)->equip(tmp);
		}
		tmp = (*src)->createMateria("ice");
		if (tmp)
		{
			std::cout << "Materia name : " << tmp->getType() << std::endl;
			(*me)->equip(tmp);
		}
		tmp = (*src)->createMateria("ice");
		if (tmp)
		{
			std::cout << "Materia name : " << tmp->getType() << std::endl;
			(*me)->equip(tmp);
		}
		tmp = (*src)->createMateria("cure");
		if (tmp)
		{
			std::cout << "Materia name : " << tmp->getType() << std::endl;
			(*me)->equip(tmp);
		}
		(*me)->use(0, **me);
		(*me)->use(1, **me);
		(*me)->use(2, **me);
		(*me)->use(3, **me);
	}
}

int	main(void)
{
	std::cout << "\033[32m" << std::endl;
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
		me->unequip(1);
	}
	equipMateria(&src, &me);
	std::cout << std::endl << std::endl;
	std::cout << "\033[33m" << std::endl;
	copySourceMateria(dynamic_cast<MateriaSource&>(*src));
	std::cout << "\033[34m" << std::endl;
	std::cout << std::endl << std::endl;
	copyCharacter();
	std::cout << std::endl << std::endl;
	std::cout << "\033[32m" << std::endl;
	delete me;
	if (tmp_unequip)
		delete tmp_unequip;
	delete src;
	std::cout << "\033[37m" << std::endl;
	return (0);
}
