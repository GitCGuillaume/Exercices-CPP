#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>

class	Convert
{
	std::string	_str;
	double		_double;
	float		_float;
	int		_int;
	char		_char;
	bool		_is_double;
	bool		_is_float;
	bool		_is_int;
	bool		_is_char;
	bool		_is_char_displayable;

	public:
		Convert(void);
		~Convert(void);
		Convert(Convert const & src);
		Convert & operator=(Convert const & src);
		void	convertToDouble(const double value);
		void	convertToFloat(const double value);
		void	convertToInt(const double value);
		void	convertToChar(const double value);
		void	setString(const char *str);
		std::string	getString(void) const;
		void	findValid(void);
		int	valuesValid(void) const;
		void	reset(void);
		void	showValues(void) const;
		void	convertCharToInt(void);
		class Impossible : public std::exception
		{
			public:
				virtual const char*	getImpossible(void) const throw();
		};
		class Nan : public std::exception
		{
			public:
				virtual const char*	getNan(void) const throw();
		};
		class Nanf : public std::exception
		{
			public:
				virtual const char*	getNanf(void) const throw();
		};
		class Inf : public std::exception
		{
			public:
				virtual const char*	getInf(void) const throw();
		};
		class Inf2 : public std::exception
		{
			public:
				virtual const char*	getInf(void) const throw();
		};
};

#endif
