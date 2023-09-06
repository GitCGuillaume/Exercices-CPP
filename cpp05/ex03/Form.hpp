#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class Form
{
	private:
		const std::string	name;
		const unsigned int		_required_signed_grade;
		const unsigned int		_required_executed_grade;
		bool		_signed;

	public:
		Form();
		Form(const std::string _name, const unsigned int sign_grade, const unsigned int execute_grade);
		virtual ~Form(void);
		Form(const Form &src);
		virtual Form &	operator=(const Form &src);
		virtual std::string const &	getName(void) const;
		virtual unsigned int const &	getRequiredSignedGrade(void) const;
		virtual unsigned int const &	getRequiredExecutedGrade(void) const;
		virtual bool const &	getSigned(void) const;
		virtual void	beSigned(const Bureaucrat & src);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char*	getFormNotSigned(void) const throw();
	};
};

std::ostream &	operator<<(std::ostream & os, const Form & src);

#endif
