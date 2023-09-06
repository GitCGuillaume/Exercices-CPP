/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:42:31 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/03 10:32:10 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}
Brain & Brain::operator=(Brain const & src)
{
	std::cout << "Brain assignation" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea(unsigned int i) const
{
	if (i >= 0 && i <= 99)
		return (this->ideas[i]);
	return (std::string("but the animal forgot it."));
}

void		Brain::setIdea(std::string str, unsigned int i)
{
	if (i >= 0 && i <= 99)
		this->ideas[i] = str;
}