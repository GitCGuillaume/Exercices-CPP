/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:58:07 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/02 16:42:49 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	ft_cpy(void)
{
	ScavTrap	character_three(std::string("ScavTrap three"));
	ScavTrap	character_four(std::string("ScavTrap four"));
	ScavTrap	character_cpy(character_three);

	for (int i = 0; i < 51; i++)
	{
		character_cpy.attack("Character three");
		character_three.takeDamage((unsigned int)10);
	}
}

int	main(void)
{
	ClapTrap	character_one(std::string("Character one"));
	ClapTrap	character_two(std::string("Character two"));
	ScavTrap	scav_one(std::string("ScavTrap one"));
	ScavTrap	scav_two(std::string("ScavTrap two"));

	character_one.attack("Character two");
	character_two.takeDamage((unsigned int)10);
	character_two.takeDamage((unsigned int)10);
	character_two.beRepaired((unsigned int)4294967295);
	character_two.beRepaired((unsigned int)10);
	scav_one.attack("scav two");
	scav_two.takeDamage((unsigned int)10);
	scav_two.takeDamage((unsigned int)10);
	scav_two.beRepaired((unsigned int)4294967295);
	scav_two.beRepaired((unsigned int)10);
	std::cout << "***** COPY SCAVTRAP TEST *****" << std::endl;
	ft_cpy();
	return (0);
}
