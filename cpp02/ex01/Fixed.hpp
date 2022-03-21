#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	private:
		int	_fixed_point;
		static const int	_stock_bits = 8;
	
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		Fixed(Fixed const & cpy);
		Fixed &	operator=(Fixed const & overload);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
};

std::ostream & operator<<(std::ostream & os, Fixed const & val);

#endif
