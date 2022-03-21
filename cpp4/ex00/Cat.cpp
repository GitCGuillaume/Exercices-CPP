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

Cat::Cat(void)
{
	this->type = std::string("Cat");
	std::cout << this->type << " constructor created" << std::endl;
}
Cat::~Cat(void)
{
	std::cout << this->type << " destructor." << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	*this = src;
}

Cat & Cat::operator=(Cat const & src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " make cat sound." << std::endl;
	return ;
}
