#include "Bureaucrat.hpp"

void	sign_form(std::string str, int sign_grade, int execute_grade, int lvl)
{
	try
	{
		std::cout << std::endl;
		Bureaucrat	worker(std::string("Out of scope_0"), lvl);
		Form		form(str, sign_grade, execute_grade);

		std::cout << form << std::endl;
		worker.signForm(form);
		std::cout << form << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
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
	return ;
}

int	main(void)
{

	std::cout << "\033[36m---------- OUT OF SCOPE ----------" << std::endl;
	sign_form(std::string("Out of scope_0"), 99, 100, 0);
	sign_form( std::string("Out of scope_151"), 99, 100, 151);
	sign_form(std::string("Out of scope_0"), 0, 100, 100);
	sign_form(std::string("Out of scope_151"), 151, 100, 100);
	sign_form(std::string("Out of scope_0"), 100, 0, 100);
	sign_form(std::string("Out of scope_151"), 100, 151, 100);
	std::cout << "---------- END OUT OF SCOPE ----------" << std::endl;
	std::cout << "\033[33m" << std::endl;
	sign_form(std::string("Worker_145"), 144, 100, 145);
	sign_form(std::string("Worker_145"), 145, 100, 145);
	sign_form(std::string("Worker_145"), 146, 100, 145);
	std::cout << "\033[37m" <<  std::endl;
	
	return (0);
}
