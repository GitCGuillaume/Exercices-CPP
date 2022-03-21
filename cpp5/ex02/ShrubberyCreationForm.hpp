#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <fstream>

class	Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &	operator=(const ShrubberyCreationForm &src);
		std::string const &	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;
	
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char*	getFormNotSigned(void) const throw();
	};
};

#endif
