/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:49:17 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/15 15:06:20 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main(void)
{
	int	N = 0;
	std::string number_zombie;
	Zombie	*zombies;

	while (N <= 0)
	{
		std::cout << "Enter a zombie nomber..." << std::endl;
		getline(std::cin, number_zombie);
		std::stringstream(number_zombie) >> N;
		if (N <= 0)
			std::cout << "Not enough zombies" << std::endl;
	}
	zombies = zombieHorde(N, "name");
	if (N > 0)
		std::cout << "The horde zombie is going to be decimate." << std::endl;
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
