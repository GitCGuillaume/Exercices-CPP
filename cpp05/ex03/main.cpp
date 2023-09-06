#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_ex03(std::string str1, std::string str2)
{
	try
	{
		Bureaucrat	worker(std::string("worker"), 1);
		Intern	someRandomIntern;
		Intern	intern_cp(someRandomIntern);
		Form*	form;

		form = someRandomIntern.makeForm(str1, str2);
		if (form)
		{
			worker.signForm(*form);
			worker.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	test_ex03(std::string("robotomy request"), std::string("Bender"));
	test_ex03(std::string("shrubbery creation"), std::string("Bender"));
	test_ex03(std::string("presidential pardon"), std::string("Bender"));
	test_ex03(std::string("presidential pardon"), "qsdqdqd");
	test_ex03(std::string("qsdqsdsq"), std::string("Bender"));
	return (0);
}
