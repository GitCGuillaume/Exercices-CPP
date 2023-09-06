#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>

class	Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &	operator=(const PresidentialPardonForm &src);
		void	execute(Bureaucrat const & executor) const;
		std::string const &	getTarget(void) const;
};

#endif
