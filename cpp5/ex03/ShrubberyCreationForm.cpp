#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(std::string("ShrubberyCreationForm"), 145, 137), _target(target)
{
	try{
		std::cout << "ShrubberyCreationForm constructor." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	std::cout << "Copy Form" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src.getTarget();
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		std::string	str;
		std::ofstream	ofs;

		str.assign(this->_target);
		str.append(std::string("_shrubbery"));
		ofs.open(str.c_str(), std::ios::ate | std::ios::app);
		if (0 >= executor.getGrade())
			throw GradeTooHighException();
		else if (executor.getGrade() >= 151)
			throw GradeTooLowException();
		else if (executor.getGrade() > this->getRequiredExecutedGrade())
			throw GradeTooLowException();
		if (this->getSigned() == false)
			throw FormNotSigned();
		if (ofs.is_open())
		{
			for (int i = 0; i <= 10; i++)
			{
				for (int j = 0; j <= 5; j++)
					ofs << " ";
				for (int k = 0; k <= 20; k++)
					ofs << k;
				ofs << std::endl;
			}
			for (int i = 0; i <= 10; i++)
			{
				for (int j = 0; j < 18; j++)
					ofs << " ";
				for (int k = 0; k <= 7; k++)
					ofs << k;
				ofs << std::endl;
			}
			ofs << std::endl;
		}
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

const char*	ShrubberyCreationForm::FormNotSigned::getFormNotSigned(void) const throw()
{
	return ("is not signed.");
}
