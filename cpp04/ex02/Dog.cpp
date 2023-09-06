/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:58:51 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 11:14:26 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = std::string("Dog");
	std::cout << this->type << " DOG constructor created" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(std::string name)
{
	this->type = name;
	std::cout << this->type << " DOG constructor created" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << this->type << " DOG destructor." << std::endl;
}

/*
 ** To make a deep copy, ptr must not update the
 ** initial value, so this->example = new Example;
 ** to update ptr addr
*/

Dog::Dog(const Dog & src) : Animal(src)
{
	this->type = src.type;
	std::cout << this->type << " DOG deep copy" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog & Dog::operator=(Dog const & src)
{
	std::cout << " DOG assignation" << std::endl;
	if (this != &src)
	{
		delete this->_brain;
		this->type = src.type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " make DOG sound." << std::endl;
	return ;
}

Brain *	Dog::getBrain() const
{
	return (this->_brain);
}
