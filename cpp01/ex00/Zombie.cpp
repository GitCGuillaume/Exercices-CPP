/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:28:11 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/02 10:31:29 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " killed." << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
