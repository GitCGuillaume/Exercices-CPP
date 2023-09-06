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

WrongCat::WrongCat()
{
	this->type = std::string("WrongCat");
	std::cout << this->type << " WRONGCAT constructor created" << std::endl;
}

WrongCat::WrongCat(std::string name)
{
	this->type = name;
	std::cout << this->type << " WRONGCAT constructor created" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " WRONGCAT destructor." << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
	*this = src;
	std::cout << this->type << " WRONGCAT copy constructor created" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " WRONGCAT assignation created" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->type << " make WrongCat sound." << std::endl;
	return ;
}
