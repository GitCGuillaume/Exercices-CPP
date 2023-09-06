#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

class	Bureaucrat;

class RobotomyRequestForm : public Form
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &	operator=(const RobotomyRequestForm &src);
		std::string const &	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;
};

#endif
