#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + std::string("_clap_name")), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << this->_name << " constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
	return ;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & src)
{
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "DiamondTrap " << this->_name << " assignation called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "name : " << this->_name
		<< " ClapTrap_name : " << ClapTrap::_name << std::endl;
}
