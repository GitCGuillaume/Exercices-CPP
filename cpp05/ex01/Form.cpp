#include "Form.hpp"

Form::Form() : name(), _required_signed_grade(1), _required_executed_grade(1), _signed(false)
{
	return ;
}

Form::Form(std::string _name, unsigned int sign_grade, unsigned int execute_grade) : name(_name), _required_signed_grade(sign_grade), _required_executed_grade(execute_grade), _signed(false)
{
	if (sign_grade <= 0 || execute_grade <= 0)
		throw Form::GradeTooHighException();
	if (sign_grade >= 151 || execute_grade >= 151)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	return ;
}

Form::Form(const Form &src) : name(src.name), _required_signed_grade(src._required_signed_grade),
	_required_executed_grade(src._required_executed_grade), _signed(src._signed)
{
	return ;
}

Form &	Form::operator=(const Form &src)
{
	if (this != &src)
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

void	Form::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() <= 0)
	{
		this->_signed = false;
		throw Form::GradeTooHighException();
	}
	else if (src.getGrade() >= 151)
	{
		this->_signed = false;
		throw Form::GradeTooLowException();
	}
	if (this->getRequiredSignedGrade() >= src.getGrade())
	{
		this->_signed = true;
		return ;
	}
	throw Form::GradeTooLowException();
}

std::ostream &	operator<<(std::ostream & os, const Form & src)
{
	os << "Name : " << src.getName()
		<< " Required signed grade : " << src.getRequiredSignedGrade()
		<< " Required executed grade : " << src.getRequiredExecutedGrade()
		<< " Signed Form : " << src.getSigned();
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
