#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap " << this->_name << " copy constructor called." << std::endl;
	*this = src;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ScavTrap " << this->_name << " copy constructor called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " ScavTrap have no energy left to attack." << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " ScavTrap have no hitpoint left to attack." << std::endl;
		return ;
	}
	this->_energyPoints = this->_energyPoints - 1;
	std::cout << this->_name << " ScavTrap attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " ScavTrap have no energy left to guard gate." << std::endl;
		return ;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " ScavTrap have no hitpoint left to guard gate." << std::endl;
		return ;
	}
	std::cout << this->_name << " ScavTrap is guarding the gate." << std::endl;
}
