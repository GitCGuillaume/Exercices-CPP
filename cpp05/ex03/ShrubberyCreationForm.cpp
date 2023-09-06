#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(std::string("ShrubberyCreationForm"), 145, 137), _target()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(std::string("ShrubberyCreationForm"), 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	return ;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string	str;
	std::ofstream	ofs;

	str.assign(this->_target);
	str.append(std::string("_shrubbery"));
	if (this->getSigned() == false)
		throw Form::FormNotSigned();
	if (0 >= executor.getGrade())
		throw Form::GradeTooHighException();
	else if (executor.getGrade() >= 151)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getRequiredExecutedGrade())
		throw Form::GradeTooLowException();
	ofs.open(str.c_str(), std::ios::ate | std::ios::trunc);
	if (ofs.is_open())
	{
		std::cout << "Open : " << this->getTarget() << std::endl;
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
	ofs.close();
}