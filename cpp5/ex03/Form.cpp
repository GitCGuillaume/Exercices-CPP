#include "Form.hpp"

Form::Form(std::string _name, unsigned int sign_grade, unsigned int execute_grade) : name(_name), _required_signed_grade(sign_grade), _required_executed_grade(execute_grade), _signed(0)
{
	try{
		if (sign_grade <= 0 || execute_grade <= 0)
			throw GradeTooHighException();
		if (sign_grade >= 151 || execute_grade >= 151)
			throw GradeTooLowException();
		std::cout << "Form constructor." << std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::~Form()
{
	std::cout << "Form destructor." << std::endl;
}

Form::Form(const Form &src) : name(src.name), _required_signed_grade(src._required_signed_grade),
	_required_executed_grade(src._required_executed_grade), _signed(src._signed)
{
	std::cout << "Copy Form" << std::endl;
}

Form &	Form::operator=(const Form &src)
{
	this->_signed = src._signed;
	return (*this);
}

std::string const &	Form::getName(void) const
{
	return (this->name);
}

unsigned int const &	Form::getRequiredSignedGrade(void) const
{
	return (this->_required_signed_grade);
}
unsigned int const &	Form::getRequiredExecutedGrade(void) const
{
	return (this->_required_executed_grade);
}
bool const &	Form::getSigned(void) const
{
	return (this->_signed);
}

Form &	Form::beSigned(const Bureaucrat & src)
{
	try
	{
		if (0 >= src.getGrade())
		{
			throw GradeTooHighException();
		}
		else if (src.getGrade() >= 151)
		{
			throw GradeTooLowException();
		}
		if (this->getRequiredSignedGrade() < src.getGrade())
		{
			throw GradeTooLowException();
			return (*this);
		}
		this->_signed = true;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << "Required " <<  e.getGradeTooHighException() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << "Required " << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, const Form & src)
{
	os << "Name : " << src.getName()
		<< " Required signed grade : " << src.getRequiredSignedGrade()
		<< " Required executed grade : " << src.getRequiredExecutedGrade()
		<< " Signed Form : " << src.getSigned() << std::endl;
	return (os);
}

/* GRADEEXCEPTION */

const char*	Form::GradeTooHighException::getGradeTooHighException(void) const throw()
{
	return ("Grade is too high.");
}
const char*	Form::GradeTooLowException::getGradeTooLowException(void) const throw()
{
	return ("Grade is too low.");
}
