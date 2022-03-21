/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:58:51 by gchopin           #+#    #+#             */
/*   Updated: 2021/12/15 10:45:44 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = std::string("Dog");
	std::cout << this->type << " constructor created" << std::endl;
}
Dog::~Dog(void)
{
	std::cout << this->type << " destructor." << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	*this = src;
	std::cout << this->type << " copy constructor created" << std::endl;
	return ;
}

Dog & Dog::operator=(Dog const & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " assignation created" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " make dog sound." << std::endl;
	return ;
}
