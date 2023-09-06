/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:58:51 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/20 12:16:12 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = std::string("Cat");
	std::cout << this->type << " CAT constructor created" << std::endl;
}

Cat::Cat(std::string name)
{
	this->type = name;
	std::cout << this->type << " CAT constructor created" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " CAT destructor." << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	*this = src;
	std::cout << this->type << " CAT copy constructor created" << std::endl;
}

Cat & Cat::operator=(Cat const & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " CAT assignation created" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " make cat sound." << std::endl;
	return ;
}
