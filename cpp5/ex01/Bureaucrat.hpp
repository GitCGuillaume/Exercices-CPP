#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>

class	Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		note;
	
	public:
		Bureaucrat(std::string const _name, unsigned int _note);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat & src);
		Bureaucrat &	operator=(const Bureaucrat & src);
		void	signForm(const Form & src) const;
		/* Getters */
		const std::string &	getName(void) const;
		const unsigned int &	getGrade(void) const;
		/* SETTERS */
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
