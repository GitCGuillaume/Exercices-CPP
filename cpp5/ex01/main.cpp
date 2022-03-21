#include "Bureaucrat.hpp"

void	sign_form(Bureaucrat worker, std::string str, int sign_grade, int execute_grade)
{
	std::cout << std::endl;
	Form		form(str, sign_grade, execute_grade);

	std::cout << form;
	form.beSigned(worker);
	worker.signForm(form);
	std::cout << form;
	return ;
}

int	main(void)
{
	Bureaucrat	worker(std::string("Out of scope"), 0);
	Bureaucrat	worker_2(std::string("Normal scope"), 100);
	Bureaucrat	worker_3(std::string("Too high"), 1);
	Bureaucrat	worker_4(std::string("Too Low"), 150);
	Bureaucrat	worker_5(std::string("Out of scope"), 151);
	Bureaucrat	worker_6(std::string("Normal scope"), 5);

	std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
	std::cout << "Increment" << std::endl;
	worker_2.incGrade();
	std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
	std::cout << "Decrement" << std::endl;
	worker_2.decGrade();
	std::cout << "Name : " << worker_2.getName() << " Rank : " << worker_2.getGrade() << std::endl;
	
	std::cout << "Name : " << worker_3.getName() << " Rank : " << worker_3.getGrade() << std::endl;
	worker_3.incGrade();
	std::cout << "Name : " << worker_3.getName() << " Rank : " << worker_3.getGrade() << std::endl;
	
	std::cout << "Name : " << worker_4.getName() << " Rank : " << worker_4.getGrade() << std::endl;
	worker_4.decGrade();
	std::cout << "Name : " << worker_4.getName() << " Rank : " << worker_4.getGrade() << std::endl;
	worker_4.decGrade();

	std::cout << worker;
	std::cout << worker_2;
	std::cout << worker_3;
	std::cout << worker_4;
	std::cout << worker_5;
	std::cout << std::endl;
	std::cout << "---------- OUT OF SCOPE ----------" << std::endl;
	sign_form(worker, std::string("I am out of scope"), 0, 0);
	sign_form(worker, std::string("I am out of scope"), 5, 0);
	sign_form(worker, std::string("I am out of scope"), 0, 5);
	sign_form(worker, std::string("I am out of scope"), 5, 5);
	sign_form(worker_5, std::string("I am out of scope"), 5, 5);
	std::cout << "---------- END OUT OF SCOPE ----------" << std::endl;
	sign_form(worker_2, std::string("I need 5 or less"), 5, 5);
	sign_form(worker_3, std::string("I am good 1"), 5, 5);
	sign_form(worker_6, std::string("I am good 5"), 5, 5);
	std::cout << std::endl;
	return (0);
}
