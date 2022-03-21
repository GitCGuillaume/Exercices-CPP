#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(std::string("RobotomyRequestForm"), 72, 45), _target(target)
{
	try{
		std::cout << "RobotomyRequestForm constructor." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	std::cout << "Copy Form" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	random_value = 0;

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
		std::cout << "VVVVVVVVVVVVV ";
		std::srand(time(0));
		random_value = std::rand() & 100;
		if (random_value <= 50)
			std::cout << "Robomized" << std::endl;
		else
			std::cout << "drill broke..." << std::endl;
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

const char*	RobotomyRequestForm::FormNotSigned::getFormNotSigned(void) const throw()
{
	return ("is not signed.");
}
