#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(std::string("PresidentialPardonForm"), 25, 5), _target()
{
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(std::string("PresidentialPardonForm"), 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_target = src.getTarget();
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSigned();
	if (0 >= executor.getGrade())
		throw Form::GradeTooHighException();
	else if (executor.getGrade() >= 151)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getRequiredExecutedGrade())
		throw Form::GradeTooLowException();
	std::cout << this->_target << " has been forgiven by Zafod Beeblebrox." << std::endl;
}