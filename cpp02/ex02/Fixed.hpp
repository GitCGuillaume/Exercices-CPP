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
		bool	operator>(Fixed const & overload) const;
		bool	operator<(Fixed const & overload) const;
		bool	operator>=(Fixed const & overload) const;
		bool	operator<=(Fixed const & overload) const;
		bool	operator==(Fixed const & overload) const;
		bool	operator!=(Fixed const & overload) const;
		Fixed	operator+(Fixed const & overload) const;
		Fixed	operator-(Fixed const & overload) const;
		Fixed	operator*(Fixed const & overload) const;
		Fixed	operator/(Fixed const & overload) const;
		/* prefix */
		Fixed &	operator++(void);
		Fixed &	operator--(void);
		/* postfix */
		Fixed	operator++(int);
		Fixed	operator--(int);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int	toInt(void) const;
		static Fixed &	min(Fixed & one, Fixed & two);
		static const Fixed &	min(Fixed const &one, Fixed const &two);
		static Fixed &	max(Fixed & one, Fixed & two);
		static const Fixed &	max(Fixed const & one, Fixed const & two);
};

std::ostream & operator<<(std::ostream & os, Fixed const & val);

#endif
