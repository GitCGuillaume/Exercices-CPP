/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:28:47 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 10:16:17 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	wrongCat(void)
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << "Animal type is " << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete i;
	delete meta;
}

void	nonConst(void)
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	Animal cpy(*j);

	std::cout << "Animal type is " << j->getType() << " " << std::endl;
	std::cout << "Animal type is " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	cpy.makeSound();
	meta->makeSound();
	delete j;
	delete i;
	delete meta;
}

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal cpy(*j);

	std::cout << "\033[35mNOT CONST CLASSES" << std::endl;
	nonConst();
	std::cout << "\033[32mCONST CLASSES" << std::endl;
	std::cout << "Animal type is " << j->getType() << " " << std::endl;
	std::cout << "Animal type is " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	cpy.makeSound();
	meta->makeSound();
	std::cout << "\033[37m*** WRONG CAT ***" << std::endl;
	wrongCat();
	std::cout << "*** END WRONG ***" << std::endl;
	delete j;
	delete i;
	delete meta;
	return (0);
}
