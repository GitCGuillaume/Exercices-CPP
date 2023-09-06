#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : grade(0)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const _name, unsigned int _grade) : name(_name), grade(_grade)
{
		if (this->grade <= 0)
			throw Bureaucrat::GradeTooHighException();
		else if (this->grade >= 151)
			throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : name(src.name)
{
	this->grade = src.grade;
}

Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & src)
{
	if (this != &src)
		this->grade = src.grade;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, const Bureaucrat & src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}

/* Getters */

const std::string &	Bureaucrat::getName(void) const
{
	return (this->name);
}

const unsigned int &	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void		Bureaucrat::incGrade(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= 1;
}

void		Bureaucrat::decGrade(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += 1;
}

void	Bureaucrat::signForm(Form & src)
{
	try
	{
		src.beSigned(*this);
		if (src.getSigned() == true)
			std::cout << this->getName() << " signed " << src.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn't sign "
			<< src.getName() << " because " << e.getGradeTooLowException() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << this->getName() << " couldn't sign "
			<< src.getName() << " because " << e.getGradeTooHighException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign "
			<< src.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << this->name << " couldn't execute form because " << e.getGradeTooHighException() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << this->name << " couldn't execute form because " << e.getGradeTooLowException() << std::endl;
	}
	catch (Form::FormNotSigned& e)
	{
		std::cerr << this->name << " couldn't execute form because " << e.getFormNotSigned() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << this->name << " couldn't execute form because " << e.what() << std::endl;
	}
}

/* GRADEEXCEPTION */

const char*	Bureaucrat::GradeTooHighException::getGradeTooHighException(void) const throw()
{
	return ("Grade is too high.");
}
const char*	Bureaucrat::GradeTooLowException::getGradeTooLowException(void) const throw()
{
	return ("Grade is too low.");
}
