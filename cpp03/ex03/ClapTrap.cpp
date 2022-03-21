/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:24:21 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/18 13:57:53 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
	return ;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap (ClapTrap const & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ClapTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ClapTrap " << this->_name << "assignation called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " have no energy left to attack." << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " have no hitpoint left to attack." << std::endl;
		return ;
	}
	this->_energyPoints = this->_energyPoints - 1;
	std::cout << this->_name << " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if ((this->_hitPoints) > 0 && amount >= 0 && amount <= (unsigned int)4294967295)
	{
		std::cout << this->_name << " take " << amount << " damage." << std::endl;
		this->_hitPoints -= amount;
		if (this->_hitPoints == 0)
			std::cout << this->_name << " is dead" << std::endl;
	}
	else if (this->_hitPoints <= 0)
		std::cout << this->_name << " is already dead" << std::endl;
	else
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " have no energy left to be repaired." << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " have no hitpoint left to be repaired." << std::endl;
		return ;
	}
	if (amount >= 0 && amount <= (unsigned int)4294967295)
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " recover " << amount << "HP." << std::endl;
	}
	else
	{
		this->_hitPoints = (unsigned int)4294967295;
		std::cout << this->_name << "recover " << this->_hitPoints << " HP." << std::endl;
	}
	this->_energyPoints = this->_energyPoints - 1;
}
