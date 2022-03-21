/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:20:42 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/17 17:43:37 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void	test(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;	
}

int	main(void)
{
	Fixed		a((float)3);
	Fixed		zero((float)0);
	Fixed		b((float)2);
	Fixed		c(b);
	Fixed		d(a);
	Fixed	const	e((float)2.5f);
	Fixed	const	f((float)3.5f);
	Fixed		g;
	Fixed const	h(Fixed(5.05f) * Fixed(2));
	Fixed		i((float)2.5f);

	test();
	if (a > b)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	if (b < a)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	if (b >= c)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	if (b <= c)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	if (b == c)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	if (a != c)
		std::cout << "ok" << std::endl;
	else
		std::cout << "no" << std::endl;
	std::cout << "Should be 3+2=5 : " << a + b << std::endl;
	std::cout << "Should be 3+2+2=7 : "  << a + b + c << std::endl;
	std::cout << "Should be 3-2-2=-1 : "  << a - b - c << std::endl;
	std::cout << "Should be 3*2=6 : "  << a * b << std::endl;
	std::cout << "Should be 3*2*2=12 : "  << a * b * c << std::endl;
	std::cout << "Should be 1.5 : "  << a / b << std::endl;
	std::cout << "Should be 0 : "  << a / zero << std::endl;
	std::cout << "Should be 2.5*2.5=6.25 : "  << i * i << std::endl;
	std::cout << "Should be 2.5+2.5=5 : "  << i + i << std::endl;
	std::cout << "Should be 2.5/2.5=1 : "  << i / i << std::endl;
	std::cout << "Should be 2.5-2.5=0 : "  << i - i << std::endl;
	std::cout << "++" << std::endl;
	std::cout << "a " <<  a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "b++ " << b++ << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "++b " << ++b << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "--" << std::endl;
	std::cout << "c " << c << std::endl;
	std::cout << "c " << c-- << std::endl;
	std::cout << "c " << c << std::endl;
	std::cout << "d " << d << std::endl;
	std::cout << "d " << --d << std::endl;
	std::cout << "d " << d << std::endl;
	std::cout << "min a b: " << Fixed::min(a, b) << std::endl;
	std::cout << "min const e f : " << Fixed::min(e, f) << std::endl;
	std::cout << "max a b : "  << Fixed::max(a, b) << std::endl;
	std::cout << "max const e f : " << Fixed::max(e, f) << std::endl;
	std::cout << "g " << g << std::endl;
	std::cout << "++g " << ++g << std::endl;
	std::cout << "g " << g << std::endl;
	std::cout << "g++ " << g++ << std::endl;
	std::cout << "g " << g << std::endl;
	std::cout << "h " << h << std::endl;
	std::cout << "max g h " << Fixed::max(g, h) << std::endl;
	std::cout << "min g h " << Fixed::min(g, h) << std::endl;
	return (0);
}
