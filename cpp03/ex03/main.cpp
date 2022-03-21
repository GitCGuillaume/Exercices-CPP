/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:58:07 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/18 18:24:00 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond(std::string("Diamond"));
	DiamondTrap	diamond_cpy(diamond);

	diamond.whoAmI();
	diamond.attack("someone");
	for (int i = 0; i < 5; i++)
		diamond.takeDamage(20);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond_cpy.whoAmI();
	diamond_cpy.attack("someone");
	diamond_cpy.guardGate();
	diamond_cpy.highFivesGuys();
	return (0);
}
