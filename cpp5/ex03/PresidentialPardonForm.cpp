#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(std::string("PresidentialPardonForm"), 25, 5), _target(target)
{
	try{
		std::cout << "PresidentialPardonForm constructor." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	std::cout << "Copy Form" << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (0 >= executor.getGrade())
			throw GradeTooHighException();
		else if (executor.getGrade() >= 151)
			throw GradeTooLowException();
		else if (executor.getGrade() > this->getRequiredExecutedGrade())
			throw GradeTooLowException();
		if (this->getSigned() == false)
			throw FormNotSigned();
		std::cout << this->_target << " has been forgiven by Zafod Beeblebrox." << std::endl;
	}
	catch (FormNotSigned& e)
	{
		std::cerr << this->getName() << e.getFormNotSigned() << std::endl;
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << this->getName() << " cannot execute because " << e.getGradeTooLowException() << std::endl;
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << this->getName() << " cannot execute because " << e.getGradeTooHighException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char*	PresidentialPardonForm::FormNotSigned::getFormNotSigned(void) const throw()
{
	return ("is not signed.");
}
