#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const _name, unsigned int _note) : name(_name), note(_note)
{
	try
	{
		if (_note <= 0)
			throw GradeTooHighException();
		else if (_note >= 151)
			throw GradeTooLowException();
		std::cout << "Bureaucrat constructor" << std::endl;
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & src) : name(src.name)
{
	this->note = src.note;
}

Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & src)
{
	this->note = src.note;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, const Bureaucrat & src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

/* Getters */

const std::string &	Bureaucrat::getName(void) const
{
	return (this->name);
}

const unsigned int &	Bureaucrat::getGrade(void) const
{
	return (this->note);
}

/* SETTERS */

void		Bureaucrat::incGrade(void)
{
	try
	{
		if (this->note - 1 < 1)
			throw GradeTooHighException();
		this->note -= 1;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
void		Bureaucrat::decGrade(void)
{
	try
	{
		if (this->note + 1 > 150)
			throw GradeTooLowException();
		this->note += 1;
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

void	Bureaucrat::signForm(Form const & src) const
{
	try{	
		if (0 >= this->getGrade())
		{
			throw GradeTooHighException();
		}
		else if (this->getGrade() >= 151)
		{
			throw GradeTooLowException();
		}
		else if (this->getGrade() > src.getRequiredSignedGrade())
		{
			throw GradeTooLowException();
		}
		if (src.getSigned() == true)
			std::cout << this->getName() << " signed " << src.getName() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn't sign " << src.getName() << " because " << e.getGradeTooLowException() << std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << this->getName() << " couldn't sign " << src.getName() << " because " << e.getGradeTooHighException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
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
