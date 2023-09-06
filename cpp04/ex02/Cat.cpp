/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:58:51 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 11:14:50 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = std::string("Cat");
	std::cout << this->type << " CAT constructor created" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(std::string name)
{
	this->type = name;
	std::cout << this->type << " CAT constructor created" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << this->type << " CAT destructor." << std::endl;
}

/*
 ** To make a deep copy, ptr must not update the
 ** initial value, so this->example = new Example;
 ** to update ptr addr
*/

Cat::Cat(const Cat & src) : Animal(src)
{
	this->type = src.type;
	std::cout << this->type << " CAT deep copy" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat & Cat::operator=(Cat const & src)
{
	std::cout << this->type << " CAT assignation" << std::endl;
	if (this != &src)
	{
		delete this->_brain;
		this->type = src.type;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " make CAT sound." << std::endl;
	return ;
}

Brain *	Cat::getBrain() const
{
	return (this->_brain);
}