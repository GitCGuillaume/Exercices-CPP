#include "Convert.hpp"

Convert::Convert(void)
{
	this->_is_double = false;
	this->_is_float = false;
	this->_is_int = false;
	this->_is_char = false;
	this->_double = 0.000000;
	this->_float = 0.000000;
	this->_int = 0;
	this->_char = 0;
}
Convert::~Convert(void)
{
	return ;
}

Convert::Convert(Convert const & src)
{
	this->_str = src._str;
	this->_double = src._double;
	this->_float = src._float;
	this->_int = src._int;
	this->_char = src._char;
	this->_is_double = src._is_double;
	this->_is_float = src._is_float;
	this->_is_int = src._is_int;
	this->_is_char = src._is_char;
	return ;
}

Convert & Convert::operator=(Convert const & src)
{
	if (this != &src)
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
	}
	return (*this);
}

void	Convert::detectType(std::string str)
{
	double	value = std::strtod(str.c_str(), NULL);
	int		i = 0;
	bool	decimal = false;
	bool	_float = false;

	if (value == std::numeric_limits<double>::infinity())
	{
		this->_is_double = true;
		this->_double = std::numeric_limits<double>::infinity();
		return ;
	}
	else if (value == -std::numeric_limits<double>::infinity())
	{
		this->_is_double = true;
		this->_double = -std::numeric_limits<double>::infinity();
		return ;
	}
        if (value == std::numeric_limits<float>::infinity())
	{
		this->_is_float = true;
		this->_double = std::numeric_limits<float>::infinity();
		return ;
	}
	else if (value == -std::numeric_limits<float>::infinity())
	{
		this->_is_float = true;
		this->_double = -std::numeric_limits<float>::infinity();
		return ;
	}
	while (str[i])
		i++;
	if (i == 1 && std::isprint(str[0]) > 0 
		&& std::isdigit(str[0]) == 0)
	{
		this->_is_char = true;
		return ;
	}
	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i])
	{
		if (str[i] == '.' && decimal == true)
			return ;
		else if (str[i] != '\0' && _float == true)
			return ;
		else if (str[i] == '.' && i != 0 && decimal == false)
		{
			decimal = true;
			i++;
		}
		else if (std::isdigit(str[i]) > 0)
			i++;
		else if (str[i] == 'f' && _float == false)
		{
			_float = true;
			i++;
		}
		else if (str[i] != '\0')
			return ;
	}
	if (i > 0)
		i--;
	if (decimal == true && str[i] == 'f')
	{
		this->_is_float = true;
		return ;
	}
	else if (decimal == true)
	{
		this->_is_double = true;
		return ;
	}
	else
		this->_is_int = true;
}

void	displayFloat(float value, bool is_float)
{
	if (is_float == true)
	{
		if (value == std::floor(value))
			std::cout << "float : " << value << ".0f" << std::endl;
		else
			std::cout << "float : " << value << "f" << std::endl;
	}
}

void	displayDouble(double value, bool is_double)
{
	if (is_double == true)
	{
		if (value == std::floor(value))
			std::cout << "double : " << value << ".0"<< std::endl;
		else
			std::cout << "double : " << value << std::endl;
	}
}

void	Convert::showValues(void) const
{
	if (std::isprint(this->_char) > 0 && this->_is_char == true)
		std::cout << "char : " << this->_char << std::endl;
	else if (std::isprint(this->_char) == 0 && this->_is_char == true)
		std::cout << "char : Non displayable" << std::endl;
	if (this->getIsInteger() == true)
		std::cout << "int : " << this->_int << std::endl;
	// DISPLAY FLOAT
	displayFloat(this->_float, this->getIsFloat());
	// DISPLAY DOUBLE
	displayDouble(this->_double, this->getIsDouble());
	
}

void	Convert::convertCharToValue(void)
{
	std::ostringstream os;
	double	value = 0;
	int	i = 0;

	while (this->_str[i])
		i++;
	if (i == 1 && std::isprint(this->_str[0]) > 0
		&& std::isdigit(this->_str[0]) == 0)
	{
		value = this->_str.at(0);
		this->_str.erase();
		os.clear();
		os << value;
		this->_str.append(os.str());
	}
	return ;
}

//else if (std::isnan(value))
//	throw Nan();
void	Convert::convertToDouble(const double value)
{
	try
	{
		this->_is_double = false;
		if (value == std::numeric_limits<double>::infinity())
			throw Inf();
		else if (value == -std::numeric_limits<double>::infinity())
			throw Inf2();
		else if (value > std::numeric_limits<double>::max())
			throw Impossible();
		else if (value < -std::numeric_limits<double>::max())
			throw Impossible();
		this->_double = static_cast<double>(value);
		this->_is_double = true;
	}
	catch(Inf& e)
	{
		std::cerr << "double : " << e.getInf() << std::endl;
	}
	catch(Inf2& e)
	{
		std::cerr << "double : " << e.getInf() << std::endl;
	}
	catch(Impossible& e)
	{
		std::cerr << "double : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "double : " << e.what() << std::endl;
	}
}

//else if (std::isnan(value))
//	throw Nanf();
void	Convert::convertToFloat(const double value)
{
	try
	{
		this->_is_float = false;
		if (value == std::numeric_limits<float>::infinity())
			throw Inf();
		else if (value == -std::numeric_limits<float>::infinity())
			throw Inf2();
		else if (value > std::numeric_limits<float>::max())
			throw Impossible();
		else if (value < -std::numeric_limits<float>::max())
			throw Impossible();
		this->_float = static_cast<float>(value);
		this->_is_float = true;
	}
	catch(Inf& e)
	{
		std::cerr << "float : " << e.getInf() << "f" << std::endl;
	}
	catch(Inf2& e)
	{
		std::cerr << "float : " << e.getInf() << "f" << std::endl;
	}
	catch(Impossible& e)
	{
		std::cerr << "float : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "float : " << e.what() << std::endl;
	}
}

/*if (std::isnan(value))
throw Impossible();*/

void	Convert::convertToInt(const long value)
{
	try
	{
		this->_is_int = false;
		this->_int = 0;
		if (value > std::numeric_limits<int>::max())
			throw Impossible();
		else if (value < std::numeric_limits<int>::min())
			throw Impossible();
		this->_int = static_cast<int>(value);
		this->_is_int = true;
	}
	catch (Impossible& e)
	{
		std::cerr << "int : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "int : " << e.what() << std::endl;
	}
}

/*if (std::isnan(value))
	throw Impossible();
else */
void	Convert::convertToChar(const int value)
{
	try
	{
		this->_is_char = false;
		this->_char = 0;
		if (value > std::numeric_limits<char>::max())
			throw Impossible();
		else if (value < std::numeric_limits<char>::min())
			throw Impossible();
		this->_char = static_cast<char>(value);
		this->_is_char = true;
	}
	catch(Impossible& e)
	{
		std::cerr << "char : " << e.getImpossible() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "char : " << e.what() << std::endl;
	}
}

void	Convert::setString(const std::string str)
{
	this->_str = str;
}

std::string	Convert::getString(void) const
{
	return (this->_str);
}

bool	Convert::getIsDouble() const
{
	return (this->_is_double);
}
bool	Convert::getIsFloat() const
{
	return (this->_is_float);
}

bool		Convert::getIsInteger() const
{
	return (this->_is_int);
}

bool		Convert::getIsCharacter() const
{
	return (this->_is_char);
}

void	Convert::setIsDouble(const bool val)
{
	this->_is_double = val;
}

void	Convert::setIsFloat(const bool val)
{
	this->_is_float = val;
}

void	Convert::setIsInteger(const bool val)
{
	this->_is_int = val;
}

void	Convert::setIsCharacter(const bool val)
{
	this->_is_char = val;
}

void	Convert::setDouble(const double val)
{
	this->_double = val;	
}

void	Convert::setFloat(const float val)
{
	this->_float = val;
}

void	Convert::setInteger(const int val)
{
	this->_int = val;
}

void	Convert::setChar(const char val)
{
	this->_char = val;
}

double	Convert::getDouble() const
{
	return (this->_double);
}

float	Convert::getFloat() const
{
	return (this->_float);
}

int		Convert::getInteger() const
{
	return (this->_int);
}

char	Convert::getCharacter() const
{
	return (this->_char);
}

void	Convert::run_double(std::string const str, bool start)
{
	double	value = std::strtod(str.c_str(), NULL);

	this->convertToDouble(value);
	if (start == false)
		return ;
	this->run_float(str, false);
	this->run_int(str, false);
	this->run_char(str, false);
}

void	Convert::run_float(std::string const str, bool start)
{
	double	value = std::strtod(str.c_str(), NULL);

	this->convertToFloat(value);
	if (start == false)
		return ;
	this->run_double(str, false);
	this->run_int(str, false);
	this->run_char(str, false);
}

void	Convert::run_int(std::string const str, bool start)
{
	double	check_inf = std::strtod(str.c_str(), NULL);
	long	value = std::strtol(str.c_str(), NULL,  10);

	if (check_inf == std::numeric_limits<double>::infinity())
		value = std::numeric_limits<long>::max();
	else if (check_inf == -std::numeric_limits<double>::infinity())
		value =  std::numeric_limits<long>::min();
	this->convertToInt(value);
	if (start == false)
		return ;
	this->run_double(str, false);
	this->run_float(str, false);
	this->run_char(str, false);
}

void	Convert::run_char(std::string const str, bool start)
{
	std::ostringstream	ofs;
	std::string			new_str;
	double	check_inf = std::strtod(str.c_str(), NULL);
	int	value = 0;

	this->setString(str);
	this->convertCharToValue();
	std::istringstream(this->_str.c_str()) >> value;
	if (check_inf == std::numeric_limits<double>::infinity())
		this->convertToChar(std::numeric_limits<int>::max());
	else if (check_inf == -std::numeric_limits<double>::infinity())
		this->convertToChar(std::numeric_limits<int>::min());
	else
		this->convertToChar(value);
	if (start == false)
		return ;
	ofs.clear();
	new_str.clear();
	ofs << value;
	new_str = ofs.str();
	this->run_double(std::string(new_str), false);
	this->run_float(std::string(new_str), false);
	this->run_int(std::string(new_str), false);
}

const char*	Convert::Impossible::getImpossible(void) const throw()
{
	return ("Impossible");
}

const char*	Convert::Inf::getInf(void) const throw()
{
	return ("+inf");
}

const char*	Convert::Inf2::getInf(void) const throw()
{
	return ("-inf");
}
