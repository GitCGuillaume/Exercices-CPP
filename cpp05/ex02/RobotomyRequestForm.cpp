#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form(std::string("RobotomyRequestForm"), 72, 45), _target()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(std::string("RobotomyRequestForm"), 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), src.getRequiredSignedGrade(), src.getRequiredExecutedGrade()), _target(src._target)
{
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
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

	if (this->getSigned() == false)
		throw Form::FormNotSigned();
	if (0 >= executor.getGrade())
		throw Form::GradeTooHighException();
	else if (executor.getGrade() >= 151)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getRequiredExecutedGrade())
		throw Form::GradeTooLowException();
	std::cout << "VVVVVVVVVVVVV " << std::endl;
	std::srand(time(0));
	random_value = std::rand() & 100;
	if (random_value <= 50)
		std::cout << this->_target << " Robotomized" << std::endl;
	else
		std::cout << "drill broke..., couldn't robotomized " << this->_target << std::endl;
}