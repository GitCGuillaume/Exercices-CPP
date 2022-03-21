#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_fixed_point;
		static const int	_stock_bits = 8;
	
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const & cpy);
		Fixed &	operator=(Fixed const & overload);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
