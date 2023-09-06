/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:58:51 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/20 12:16:31 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = std::string("WrongCat");
	std::cout << this->type << " constructor created" << std::endl;
}
WrongCat::~WrongCat(void)
{
	std::cout << this->type << " destructor." << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
	*this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->type << " make WrongCat sound." << std::endl;
	return ;
}
