/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:58:07 by gchopin           #+#    #+#             */
/*   Updated: 2021/12/15 10:38:51 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	ft_cpy(void)
{
	FragTrap	character_three(std::string("FragTrap three"));
	FragTrap	character_four(std::string("FragTrap four"));
	FragTrap	character_cpy(character_three);

	for (int i = 0; i < 101; i++)
	{
		character_cpy.attack("Character three");
		character_three.takeDamage((unsigned int)10);
	}
}

int	main(void)
{
	ClapTrap	character_one(std::string("Character one"));
	ClapTrap	character_two(std::string("Character two"));
	ScavTrap	scav(std::string("Scav test"));
	FragTrap	frag(std::string("Frag"));
	FragTrap	frag_cpy(frag);

	character_one.attack("Character two");
	character_two.takeDamage((unsigned int)10);
	character_two.takeDamage((unsigned int)10);
	character_two.beRepaired((unsigned int)4294967295);
	scav.attack("Character one");
	scav.guardGate();
	character_one.takeDamage((unsigned int)5);
	frag.highFivesGuys();
	frag.takeDamage(20);
	frag.takeDamage(20);
	frag.takeDamage(20);
	frag.takeDamage(20);
	frag.takeDamage(20);
	frag.takeDamage(20);
	frag_cpy.highFivesGuys();
	frag_cpy.takeDamage(20);
	frag_cpy.takeDamage(20);
	frag_cpy.takeDamage(20);
	frag_cpy.takeDamage(20);
	frag_cpy.takeDamage(20);
	frag_cpy.takeDamage(20);
	std::cout << "***** COPY FRAGTRAP TEST *****" << std::endl;
	ft_cpy();
	return (0);
}
