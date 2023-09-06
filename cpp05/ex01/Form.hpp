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
		~Form(void);
		Form(const Form &src);
		Form &	operator=(const Form &src);
		std::string const &	getName(void) const;
		unsigned int const &	getRequiredSignedGrade(void) const;
		unsigned int const &	getRequiredExecutedGrade(void) const;
		bool const &	getSigned(void) const;
		void	beSigned(const Bureaucrat & src);

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

std::ostream &	operator<<(std::ostream & os, const Form & src);

#endif
