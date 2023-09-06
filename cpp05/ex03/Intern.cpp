#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
	return ;
}

Intern & Intern::operator=(Intern const &)
{
	return (*this);
}

Form*	newShrubbery(const std::string & str)
{
	return (new ShrubberyCreationForm(str));
}

Form*	newRobotomy(const std::string & str)
{
	return (new RobotomyRequestForm(str));
}

Form*	newPresidentialPardon(const std::string & str)
{
	return (new PresidentialPardonForm(str));
}

Form *	Intern::makeForm(const std::string & str1, const std::string & str2)
{
	try
	{
		struct s_function
		{
			Form*	(*function)(const std::string &);
		};
		struct s_function	arr[3] =
		{
			{ newShrubbery },
			{ newRobotomy },
			{ newPresidentialPardon }
		};
		std::string	str[3];
		Form	*form;

		str[0] = std::string("shrubbery creation");
		str[1] = std::string("robotomy request");
		str[2] = std::string("presidential pardon");
		for (int i = 0; i < 3; i++)
		{
			if (str[i].compare(str1) == 0)
			{
				form = arr[i].function(str2);
				std::cout << "Intern creates "
					<< form->getName() << std::endl;
				return (form);
			}
		}
		throw Intern::InternError();
	}
	catch (InternError& e)
	{
		std::cerr << e.getError() << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

const char*	Intern::InternError::getError(void) const throw()
{
	return ("Intern couldn't create a form.");
}
