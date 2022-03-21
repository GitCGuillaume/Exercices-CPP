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

Form*	newShrubbery(const char *str)
{
	return (new ShrubberyCreationForm(str));
}

Form*	newRobotomy(const char *str)
{
	return (new RobotomyRequestForm(str));
}

Form*	newPresidentialPardon(const char *str)
{
	return (new PresidentialPardonForm(str));
}

Form *	Intern::makeForm(const char *str1, const char *str2)
{
	try
	{
		struct s_function
		{
			Form*	(*function)(const char *);
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
			if (str1 && str[i].compare(str1) == 0)
			{
				form = arr[i].function(str2);
				std::cout << "Intern creates "
					<< form->getName() << std::endl;
				return (form);
			}
		}
		throw InternError();
	}
	catch (InternError& e)
	{
		std::cerr << e.getError() << std::endl;
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
