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

Dog::Dog()
{
	this->type = std::string("Dog");
	std::cout << this->type << " DOG constructor created" << std::endl;
}

Dog::Dog(std::string name)
{
	this->type = name;
	std::cout << this->type << " DOG constructor created" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " DOG destructor." << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	*this = src;
	std::cout << this->type << " DOG copy constructor created" << std::endl;
	return ;
}

Dog & Dog::operator=(Dog const & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " DOG assignation created" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " make dog sound." << std::endl;
	return ;
}
