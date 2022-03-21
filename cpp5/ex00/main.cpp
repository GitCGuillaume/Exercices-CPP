#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	worker(std::string("Out of scope"), 0);
	Bureaucrat	worker_2(std::string("Normal scope"), 100);
	Bureaucrat	worker_3(std::string("Too high"), 1);
	Bureaucrat	worker_4(std::string("Too Low"), 150);
	Bureaucrat	worker_5(std::string("Out of scope"), 151);
	
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
	return (0);
}
