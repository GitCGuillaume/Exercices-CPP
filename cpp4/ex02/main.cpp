/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:42:22 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 11:33:19 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

void	deep_copy_example(void)
{
	const Dog* dog = new Dog();
	const Cat* cat = new Cat();
	const Dog array_cpy_dog(*dog);
	const Cat array_cpy_cat(*cat);

	array_cpy_dog.makeSound();
	array_cpy_cat.makeSound();
	dog->makeSound();
	cat->makeSound();
	delete cat;
	delete dog;
	std::cout << "*** END EXAMPLE ***" << std::endl;
}

int	main(void)
{
	int	i;

	i = 0;
	Animal	*array[4];
	std::cout << "Fill array" << std::endl;
	for (i = 0; i < 2; i++)
		array[i] = new Dog();
	for (; i < 4; i++)
		array[i] = new Cat();
	for (int i = 0; i < 4; i++)
	{
		delete array[i];
	}
	std::cout << "*** DEEP COPY EXAMPLE : ***" << std::endl;
	deep_copy_example();
	return (0);
}
