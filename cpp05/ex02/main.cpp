#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	shrubberySignForm(Bureaucrat worker, std::string str)
{
	try
	{
		std::cout << std::endl;
		ShrubberyCreationForm		form(str);
		std::cout << form << std::endl;
		worker.signForm(form);
		std::cout << form << std::endl;
		std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
		worker.executeForm(form);
	}
	catch (ShrubberyCreationForm::FormNotSigned& e)
	{
		std::cerr << worker.getName() << e.getFormNotSigned() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooLowException& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.getGradeTooLowException() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooHighException& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.getGradeTooHighException() << std::endl;
	}
	catch (Form::FormNotSigned& e)
	{
		std::cerr << worker.getName() << " couldn't execute form because " << e.getFormNotSigned() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.what() << std::endl;
	}
	return ;
}

void	robotomySignForm(Bureaucrat worker, std::string str)
{
	try
	{
		std::cout << std::endl;
		RobotomyRequestForm		form(str);
		std::cout << form << std::endl;
		worker.signForm(form);
		std::cout << form << std::endl;
		std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
		worker.executeForm(form);	
	}
	catch (RobotomyRequestForm::FormNotSigned& e)
	{
		std::cerr << worker.getName() << e.getFormNotSigned() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.getGradeTooLowException() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooHighException& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.getGradeTooHighException() << std::endl;
	}
	catch (Form::FormNotSigned& e)
	{
		std::cerr << worker.getName() << " couldn't execute form because " << e.getFormNotSigned() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.what() << std::endl;
	}
	return ;
}

void	presidentialSignForm(Bureaucrat worker, std::string str)
{
	try
	{
		std::cout << std::endl;
		PresidentialPardonForm		form(str);
		std::cout << form << std::endl;
		worker.signForm(form);
		std::cout << form << std::endl;
		std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
		worker.executeForm(form);
	}
	catch (PresidentialPardonForm::FormNotSigned& e)
	{
		std::cerr << worker.getName() << e.getFormNotSigned() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException& e)
	{
		std::cerr <<worker.getName() << " cannot execute because executor " << e.getGradeTooLowException() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooHighException& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.getGradeTooHighException() << std::endl;
	}
	catch (Form::FormNotSigned& e)
	{
		std::cerr << worker.getName() << " couldn't execute form because " << e.getFormNotSigned() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.getGradeTooHighException() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.getGradeTooLowException() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << worker.getName() << " cannot execute because executor " << e.what() << std::endl;
	}
	return ;
}

int	main(void)
{
	
	Bureaucrat	worker_2(std::string("Worker_145"), 145);
	Bureaucrat	worker_3(std::string("Worker_72"), 72);
	Bureaucrat	worker_4(std::string("Worker_4"), 4);
	Bureaucrat	worker_6(std::string("worker_45"), 45);
	Bureaucrat	worker_7(std::string("worker_138"), 138);
	Bureaucrat	worker_8(std::string("worker_137"), 137);
	Bureaucrat	worker_9(std::string("worker_5"), 5);
	Bureaucrat	worker_10(std::string("worker_25"), 25);
	
	std::cout << "\033[32m" << std::endl;
	shrubberySignForm(worker_2, std::string("Worker_145"));
	shrubberySignForm(worker_3, std::string("Worker_72"));
	shrubberySignForm(worker_4, std::string("Worker_4"));
	shrubberySignForm(worker_6, std::string("Worker_45"));
	shrubberySignForm(worker_7, std::string("Worker_138"));
	shrubberySignForm(worker_8, std::string("Worker_137"));
	shrubberySignForm(worker_9, std::string("Worker_5"));

	std::cout << "\033[33m" << std::endl;
	robotomySignForm(worker_2, std::string("Worker_145"));
	robotomySignForm(worker_3, std::string("Worker_72"));
	robotomySignForm(worker_4, std::string("Worker_4"));
	robotomySignForm(worker_6, std::string("Worker_45"));
	robotomySignForm(worker_7, std::string("Worker_138"));
	robotomySignForm(worker_8, std::string("Worker_137"));
	robotomySignForm(worker_9, std::string("Worker_5"));

	std::cout << "\033[34m" << std::endl;
	presidentialSignForm(worker_2, std::string("Worker_145"));
	presidentialSignForm(worker_3, std::string("Worker_72"));
	presidentialSignForm(worker_4, std::string("Worker_4"));
	presidentialSignForm(worker_6, std::string("Worker_45"));
	presidentialSignForm(worker_7, std::string("Worker_138"));
	presidentialSignForm(worker_8, std::string("Worker_137"));
	presidentialSignForm(worker_9, std::string("Worker_5"));
	presidentialSignForm(worker_10, std::string("Worker_25"));
	std::cout << "\033[37m" << std::endl;
	return (0);
}
