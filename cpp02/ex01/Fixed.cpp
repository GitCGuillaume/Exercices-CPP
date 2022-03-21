/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:52:21 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/17 20:47:23 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = val << Fixed::_stock_bits;
	return ;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(val * (float)(1 << Fixed::_stock_bits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &	Fixed::operator=(Fixed const & overload)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = overload.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const & cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
	return ;
}

std::ostream & operator<<(std::ostream & os, Fixed const & val)
{
	os << val.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point >> Fixed::_stock_bits);
}

/* 
 * divide by 2^mantissa
 * round because it truncat
*/

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (float)(1 << Fixed::_stock_bits));
}
