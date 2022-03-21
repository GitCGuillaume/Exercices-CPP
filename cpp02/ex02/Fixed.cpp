/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:52:21 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/17 20:48:18 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed_point(0)
{
	return ;
}

Fixed::Fixed(const int val)
{
	this->_fixed_point = val << Fixed::_stock_bits;
	return ;
}

Fixed::Fixed(const float val)
{
	this->_fixed_point = roundf(val * (float)(1 << Fixed::_stock_bits));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed &	Fixed::operator=(Fixed const & overload)
{
	this->_fixed_point = overload.getRawBits();
	return *this;
}

//this is left
bool	Fixed::operator>(Fixed const & overload) const
{
	if (this->getRawBits() > overload.getRawBits())
		return (true);
	return (false);
}

//this is left
bool	Fixed::operator<(Fixed const & overload) const
{
	if (this->getRawBits() < overload.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const & overload) const
{
	if (this->getRawBits() >= overload.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const & overload) const
{
	if (this->getRawBits() <= overload.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const & overload) const
{
	if (this->getRawBits() == overload.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const & overload) const
{
	if (this->getRawBits() != overload.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const & overload) const
{
	Fixed val;

	val.setRawBits(this->getRawBits() + overload.getRawBits());
	return (val);
}

Fixed	Fixed::operator-(Fixed const & overload) const
{
	Fixed val;

	val.setRawBits(this->getRawBits() - overload.getRawBits());
	return (val);
}

Fixed	Fixed::operator*(Fixed const & overload) const
{
	Fixed val;

	val.setRawBits((this->getRawBits() * overload.getRawBits()) / (1 << this->_stock_bits));
	return (val);
}

Fixed	Fixed::operator/(Fixed const & overload) const
{
	Fixed val;

	if (overload.getRawBits() == 0)
	{
		std::cout << "Divide by zero." << std::endl;
		return (val);
	}
	val.setRawBits((float)this->getRawBits() * (float)(1 << this->_stock_bits) / overload.getRawBits());
	return (val);
}

Fixed &	Fixed::operator++(void)
{
	this->_fixed_point = this->_fixed_point + 1;
	return (*this);
}

Fixed &	Fixed::operator--(void)
{
	this->_fixed_point = this->_fixed_point - 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	mem;

	mem = *this;
	this->_fixed_point = this->_fixed_point + 1;
	return (mem);
}

Fixed	Fixed::operator--(int)
{
	Fixed	mem;

	mem = *this;
	this->_fixed_point = this->_fixed_point - 1;
	return (mem);
}

Fixed::Fixed(Fixed const & cpy)
{
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

float	Fixed::toFloat(void) const
{
	return (this->_fixed_point / (float)(1 << Fixed::_stock_bits));
}

Fixed &	Fixed::min(Fixed & one, Fixed & two)
{
	if (one < two)
	{
		return (one);
	}
	return (two);
}

const Fixed &	Fixed::min(Fixed const & one, Fixed const &two)
{
	if ((Fixed)one < two)
	{
		return (one);
	}
	return (two);
}

Fixed &	Fixed::max(Fixed & one, Fixed & two)
{
	if (one > two)
	{
		return (one);
	}
	return (two);
}

const Fixed &	Fixed::max(Fixed const & one, Fixed const & two)
{
	if ((Fixed)one > two)
	{
		return (one);
	}
	return (two);
}
