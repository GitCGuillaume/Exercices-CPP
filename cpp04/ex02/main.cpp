/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:42:22 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/23 13:44:13 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

void	deepCopyExample(void)
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();
	
	for (unsigned int i = 0; i < 100; i++)
		cat->getBrain()->setIdea(std::string("OLD IDEA CAT"), i);
	for (unsigned int i = 0; i < 100; i++)
		dog->getBrain()->setIdea(std::string("OLD IDEA DOG"), i);
	Dog	array_cpy_dog(*dog);
	Cat	array_cpy_cat = *cat;
	for (unsigned int i = 0; i < 100; i++)
		array_cpy_cat.getBrain()->setIdea(std::string("NEW IDEA CAT"), i);
	for (unsigned int i = 0; i < 100; i++)
		array_cpy_dog.getBrain()->setIdea(std::string("NEW IDEA DOG"), i);
	std::cout << "COPY CAT : " << array_cpy_cat.getBrain()->getIdea(0) << std::endl;
	std::cout << "COPY DOG : " << array_cpy_dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "CAT : " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "DOG : " << dog->getBrain()->getIdea(0) << std::endl;
	delete cat;
	delete dog;
}

int	main(void)
{
	unsigned int	i;

	i = 0;
	Animal	*array[4];
	std::cout << "Fill array" << std::endl;
	std::cout << "\033[33m";
	for (i = 0; i < 2; i++)
	{
		array[i] = new Dog();
		std::cout << "Animal type is " << array[i]->getType() << " " << std::endl;
		array[i]->makeSound();
	}
	std::cout << "\033[34m";
	for (; i < 4; i++)
	{
		array[i] = new Cat();
		std::cout << "Animal type is " << array[i]->getType() << " " << std::endl;
		array[i]->makeSound();
	}
	
	std::cout << "\033[32m*** DEEP COPY EXAMPLE : ***" << std::endl;
	deepCopyExample();
	std::cout << "*** END EXAMPLE ***" << std::endl;
	std::cout << "\033[37m";
	for (int i = 0; i < 4; i++)
		delete array[i];
	return (0);
}
