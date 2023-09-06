#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>

class	Convert
{
	private:
		std::string	_str;
		double		_double;
		float		_float;
		int			_int;
		char		_char;
		bool		_is_double;
		bool		_is_float;
		bool		_is_int;
		bool		_is_char;

	public:
		Convert(void);
		~Convert(void);
		Convert(Convert const & src);
		Convert & operator=(Convert const & src);
		void	convertToDouble(const double value);
		void	convertToFloat(const double value);
		void	convertToInt(const long value);
		void	convertToChar(const int value);
		void	detectType(std::string str);
		void	showValues(void) const;
		void	convertCharToValue(void);
		void	setString(const std::string str);
		std::string	getString(void) const;
		bool	getIsDouble() const;
		bool	getIsFloat() const;
		bool	getIsInteger() const;
		bool	getIsCharacter() const;
		void	setIsDouble(const bool val);
		void	setIsFloat(const bool val);
		void	setIsInteger(const bool val);
		void	setIsCharacter(const bool val);
		void	setDouble(const double val);
		void	setFloat(const float val);
		void	setInteger(const int val);
		void	setChar(const char val);
		double	getDouble() const;
		float	getFloat() const;
		int		getInteger() const;
		char	getCharacter() const;
		void	run_double(std::string const str, bool start);
		void	run_float(std::string const str, bool start);
		void	run_int(std::string const str, bool start);
		void	run_char(std::string const str, bool start);

		class Impossible : public std::exception
		{
			public:
				virtual const char*	getImpossible(void) const throw();
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
