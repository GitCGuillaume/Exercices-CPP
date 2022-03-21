/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:15:38 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/08 11:00:53 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon_type = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon& weapon_type)
{
	this->_weapon_type = &weapon_type;
}

void	HumanB::attack(void) const
{
	if (this->_weapon_type != NULL)
		std::cout << this->_name << " attacks with his weapon " << this->_weapon_type->getType() << std::endl;
}
