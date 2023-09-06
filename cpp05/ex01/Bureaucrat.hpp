#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>

class	Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string const _name, unsigned int _grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat &	operator=(const Bureaucrat & src);
		void	signForm(Form & src);
		/* Getters */
		const std::string &	getName(void) const;
		const unsigned int &	getGrade(void) const;
		void		incGrade(void);
		void		decGrade(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	getGradeTooHighException(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	getGradeTooLowException(void) const throw();
		};
};

std::ostream &	operator<<(std::ostream & os, const Bureaucrat & src);

#endif
