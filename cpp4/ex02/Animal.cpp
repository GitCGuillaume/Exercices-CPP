/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:19:16 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 11:32:51 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal constructor created." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor." << std::endl;
}

Animal::Animal(const Animal & src)
{
	std::cout << "Animal copy" << std::endl;
	this->type = src.type;
}

Animal & Animal::operator=(Animal const & src)
{
	std::cout << "Animal assignation" << std::endl;
	this->type = src.type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
