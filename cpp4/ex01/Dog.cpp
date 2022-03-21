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

Dog::Dog(void)
{
	this->type = std::string("Dog");
	this->_brain = new Brain();
	this->_brain->setIdea(std::string("Base idea"), 0);
	std::cout << this->type << " constructor created" << std::endl;
}
Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << this->type << " destructor." << std::endl;
}

/*
 ** To make a deep copy, ptr must not update the
 ** initial value, so this->example = new Example;
 ** to update ptr addr
*/
Dog::Dog(const Dog & src) : Animal(src)
{
	std::cout << "Dog deep copy" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(src._brain->getIdea(i), i);
	//this->_brain->setIdea(std::string("Update idea"), 0);
	this->type = src.type;
}

Dog & Dog::operator=(Dog const & src)
{
	std::cout << "Dog assignation" << std::endl;
	this->type = src.type;
	*this->_brain = *src._brain;
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(src._brain->getIdea(i), i);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " make dog sound." << std::endl;
	std::cout << this->type << " got an idea " << this->_brain->getIdea(0) << std::endl;
	return ;
}
