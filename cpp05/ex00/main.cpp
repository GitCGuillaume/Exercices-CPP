#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	worker(std::string("Out of scope"), 0);
		worker.incGrade();
		worker.decGrade();
		std::cout << worker << std::endl;
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
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	worker_5(std::string("Out of scope"), 151);
		worker_5.incGrade();
		worker_5.decGrade();
		std::cout << worker_5 << std::endl; 
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
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	worker_2(std::string("Normal scope"), 100);
		Bureaucrat	worker_3(std::string("Value 1"), 10);

		std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
		std::cout << "Increment" << std::endl;
		worker_2.incGrade();
		std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
		std::cout << "Decrement" << std::endl;
		worker_2.decGrade();
		std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
		std::cout << "Name : " << worker_3.getName() << " Rank : " << worker_3.getGrade() << std::endl
			<< "Name : " << worker_3.getName() << std::endl << "Increment" << std::endl;
		worker_3.incGrade();
		std::cout << "Name : " << worker_3.getName() << " Rank : " << worker_3.getGrade() << std::endl;
		std::cout << "Decrement x3" << std::endl;
		worker_3.decGrade();
		worker_3.decGrade();
		worker_3.decGrade();
		std::cout << "Name : " << worker_3.getName() << " Rank : " << worker_3.getGrade() << std::endl;
		std::cout << worker_2 << std::endl;
		std::cout << worker_3 << std::endl;
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
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat	worker_4(std::string("Value 150"), 150);

		std::cout << "Name : " << worker_4.getName() << " Rank : " << worker_4.getGrade() << std::endl;
		std::cout << "INCREMENT" << std::endl;
		worker_4.incGrade();
		std::cout << "Name : " << worker_4.getName() << " Rank : " << worker_4.getGrade() << std::endl;
		std::cout << "DECREMENT" << std::endl;
		worker_4.decGrade();
		std::cout << "Name : " << worker_4.getName() << " Rank : " << worker_4.getGrade() << std::endl;
		std::cout << worker_4 << std::endl;
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
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
