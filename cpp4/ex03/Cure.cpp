/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:30:02 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 13:40:12 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria(std::string("cure"))
{
	this->type = std::string("cure");
	std::cout << this->type << " constructor created." << std::endl;
}

Cure::~Cure(void)
{
	std::cout << this->type << " Destructor called." << std::endl;
}

Cure::Cure(const Cure & src) : AMateria(src)
{
	this->type = src.type;
}

Cure & Cure::operator=(const Cure &src)
{
	this->type = src.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure * materia = new Cure();
	std::cout << "Clone " << materia->getType() << " called" << std::endl;
	return (materia);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
