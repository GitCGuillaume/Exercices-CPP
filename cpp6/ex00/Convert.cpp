#include "Convert.hpp"

Convert::Convert(void)
{
	this->_is_double = false;
	this->_is_float = false;
	this->_is_int = false;
	this->_is_char = false;
	this->_is_char_displayable = false;
	std::cout << "Convert constructor" << std::endl;
}
Convert::~Convert(void)
{
	std::cout << "Convert destructor" << std::endl;
}

Convert::Convert(Convert const & src)
{
	this->_str = src._str;
	this->_str = src._double;
	this->_float = src._float;
	this->_int = src._int;
	this->_char = src._char;
	this->_is_double = src._is_double;
	this->_is_float = src._is_float;
	this->_is_int = src._is_int;
	this->_is_char = src._is_char;
	this->_is_char_displayable = src._is_char_displayable;
	return ;
}

Convert & Convert::operator=(Convert const & src)
{
	this->_str = src._str;
	this->_str = src._double;
	this->_float = src._float;
	this->_int = src._int;
	this->_char = src._char;
	this->_is_double = src._is_double;
	this->_is_float = src._is_float;
	this->_is_int = src._is_int;
	this->_is_char = src._is_char;
	this->_is_char_displayable = src._is_char_displayable;
	return (*this);
}

void	Convert::setString(const char *str)
{
	this->_str = str;
}

std::string	Convert::getString(void) const
{
	return (this->_str);
}

int	is_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	charDisplayable(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	Convert::findValid(void)
{
	std::string	str;
	int	i = 0;

	str = this->_str;
	while (str[i] && is_digit(str[i]) == 1)
		i++;
	if(str[i] != 0 && i != 0 && str[i] == '.')
	{
		i++;
		while (str[i] && is_digit(str[i]) == 1)
			i++;
		if (is_digit(str[i - 1]) == 0)
			return ;
		if (str[i] != 0 && str[i] != 'f')
			return ;
		if (str[i] == 'f')
			i++;
	}
}

int	Convert::valuesValid(void) const
{
	if (this->_is_float == false || this->_is_double == false
		|| this->_is_int == false || this->_is_char == false)
	{

		return (false);
	}
	return (true);
}

void	Convert::reset(void)
{
	this->_is_float = false;
	this->_is_double = false;
	this->_is_int = false;
	this->_is_char = false;
	this->_is_char_displayable = false;
}

void	displayFloat(float value, bool is_float)
{
	if (is_float == true)
	{
		if (std::fabs(value - (int)value) <= std::numeric_limits<double>::epsilon())
			std::cout << "float : " << value << ".0f" << std::endl;
		else
			std::cout << "float : " << value << "f" << std::endl;
	}
}

void	displayDouble(double value, bool is_double)
{
	if (is_double == true)
	{
		if (std::fabs(value - (int)value) <= std::numeric_limits<double>::epsilon())
			std::cout << "double : " << value << ".0"<< std::endl;
		else
			std::cout << "double : " << value << "" << std::endl;
	}
}

void	Convert::showValues(void) const
{
	if (charDisplayable(this->_int) == true && this->_is_char == true)
		std::cout << "char : " << this->_char << std::endl;
	else if (charDisplayable(this->_char) == false && this->_is_char == true)
		std::cout << "char : Non displayable" << std::endl;
	if (this->_is_int == true)
		std::cout << "int : " << this->_int << std::endl;
	// DISPLAY FLOAT
	displayFloat(this->_float, this->_is_float);
	// DISPLAY DOUBLE
	displayDouble(this->_double, this->_is_double);
	
}

void	Convert::convertCharToInt(void)
{
	std::ostringstream os;
	int	i = 0;
	int	value = 0;

	while (this->_str[i])
		i++;
	if (i == 1 && charDisplayable(this->_str[0]) == 1
		&& is_digit(this->_str[0]) == 0)
	{
		value = this->_str.at(0);
		this->_str.erase();
		os.clear();
		os << value;
		this->_str.append(os.str());
	}
	return ;
}

void	Convert::convertToDouble(const double value)
{
	try
	{
		if (value == std::numeric_limits<double>::infinity())
			throw Inf();
		else if (value == -std::numeric_limits<double>::infinity())
			throw Inf2();
		else if (std::isnan(value))
			throw Nan();
		else if (value > std::numeric_limits<double>::max())
			throw Impossible();
		else if (value < -std::numeric_limits<double>::max())
			throw Impossible();
		this->_double = static_cast<double>(value);
		this->_is_double = true;
	}
	catch(Inf& e)
	{
		std::cerr << "Double : " << e.getInf() << std::endl;
	}
	catch(Inf2& e)
	{
		std::cerr << "Double : " << e.getInf() << std::endl;
	}
	catch(Nan& e)
	{
		std::cerr << "Double : " << e.getNan() << std::endl;
	}
	catch(Impossible& e)
	{
		std::cerr << "Double : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Double : " << e.what() << std::endl;
	}
}

void	Convert::convertToFloat(const double value)
{
	try
	{
		if (value == std::numeric_limits<float>::infinity())
			throw Inf();
		else if (value == -std::numeric_limits<float>::infinity())
			throw Inf2();
		else if (std::isnan(value))
			throw Nanf();
		else if (value > std::numeric_limits<float>::max())
			throw Impossible();
		else if (value < -std::numeric_limits<float>::max())
			throw Impossible();
		this->_float = static_cast<float>(value);
		this->_is_float= true;
	}
	catch(Inf& e)
	{
		std::cerr << "Float : " << e.getInf() << "f" << std::endl;
	}
	catch(Inf2& e)
	{
		std::cerr << "Float : " << e.getInf() << "f" << std::endl;
	}
	catch(Nanf& e)
	{
		std::cerr << "Float : " << e.getNanf() << std::endl;
	}
	catch(Impossible& e)
	{
		std::cerr << "Float : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Float : " << e.what() << std::endl;
	}
}

void	Convert::convertToInt(const double value)
{
	try
	{
		this->_int = 0;
		if (std::isnan(value))
			throw Impossible();
		else if (value > std::numeric_limits<int>::max())
			throw Impossible();
		else if (value < std::numeric_limits<int>::min())
			throw Impossible();
		this->_int = static_cast<int>(value);
		this->_is_int = true;
	}
	catch (Impossible& e)
	{
		std::cerr << "Int : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Int : " << e.what() << std::endl;
	}
}

void	Convert::convertToChar(const double value)
{
	try
	{
		this->_char = 0;
		if (std::isnan(value))
			throw Impossible();
		else if (value > std::numeric_limits<char>::max())
			throw Impossible();
		else if (value < std::numeric_limits<char>::min())
			throw Impossible();
		this->_char = static_cast<char>(value);
		this->_is_char = true;
	}
	catch(Impossible& e)
	{
		std::cerr << "Char : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Char : " << e.what() << std::endl;
	}
}

const char*	Convert::Impossible::getImpossible(void) const throw()
{
	return ("Impossible");
}

const char*	Convert::Nan::getNan(void) const throw()
{
	return ("nan");
}

const char*	Convert::Nanf::getNanf(void) const throw()
{
	return ("nanf");
}

const char*	Convert::Inf::getInf(void) const throw()
{
	return ("inf");
}

const char*	Convert::Inf2::getInf(void) const throw()
{
	return ("-inf");
}
