/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:58:07 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/02 16:22:13 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ft_cpy(void)
{
	ClapTrap	character_three(std::string("Character three"));
	ClapTrap	character_four(std::string("Character four"));
	ClapTrap	character_cpy(character_three);

	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_cpy.attack("Character three");
	character_three.takeDamage((unsigned int)1);
	character_four.attack("Character cpy");
	character_cpy.takeDamage((unsigned int)10);
}

int	main(void)
{
	ClapTrap	character_one(std::string("Character one"));
	ClapTrap	character_two(std::string("Character two"));
	

	character_one.attack("Character two");
	character_two.takeDamage((unsigned int)10);
	character_two.takeDamage((unsigned int)10);
	character_two.beRepaired((unsigned int)4294967295);
	character_two.beRepaired((unsigned int)10);
	std::cout << "***** Copy test part *****" << std::endl;
	ft_cpy();
	return (0);
}
