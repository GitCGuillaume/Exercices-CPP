/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:30:02 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 11:48:03 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria(std::string("ice"))
{
	this->type = std::string("ice");
	std::cout << this->type << " constructor created." << std::endl;
}

Ice::~Ice(void)
{
	std::cout << this->type << " Destructor called" << std::endl;
}

Ice::Ice(const Ice & src) : AMateria(src)
{
	this->type = src.type;
	std::cout << this->type << " copy constructor created." << std::endl;
}

Ice & Ice::operator=(const Ice &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << this->type << " assignation created." << std::endl;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice * materia = new Ice();
	std::cout << "Clone " << materia->getType() << " called" << std::endl;
	return (materia);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* Shoot an ice bolt at " << target.getName() << " * " << std::endl;
}
