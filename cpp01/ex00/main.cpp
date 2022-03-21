/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:13:24 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/15 16:51:49 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie_one[4];
	std::string	zombie_name_one;
	std::string	zombie_name_two;

	zombie_name_one.assign("Heap name");
	zombie_name_two.assign("Stack name");
	//HEAP
	std::cout << "Zombies are coming from the heap !" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		zombie_one[i]
			= zombie_one[i]->newZombie(zombie_name_one.insert(zombie_name_one.length(), "new"));
		zombie_one[i]->announce();
	}
	zombie_name_one.clear();
	//Stack
	std::cout << "Zombies are coming from the stack !" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		randomChump(zombie_name_two.insert(zombie_name_two.length(), "new"));
	}
	zombie_name_two.clear();
	std::cout << "It's now time to kills heap zombies" << std::endl;
	for (int i = 0; i < 4; i++)
		delete zombie_one[i];
	return (0);
}
