#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const & src);
		Intern & operator=(Intern const &);
		Form *	makeForm(const std::string & str1, const std::string & str2);

	class InternError : public std::exception
	{
		public:
			virtual const char*	getError(void) const throw();
	};
};

#endif
