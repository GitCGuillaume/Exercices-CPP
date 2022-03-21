#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_ex03(const char *str1, const char *str2)
{
	Intern	someRandomIntern;
	Intern	intern_cp(someRandomIntern);
	Form*	rrf;

	rrf = someRandomIntern.makeForm(str1, str2);
	if (rrf)
		delete rrf;
}
void	shrubbery_sign_form(Bureaucrat worker, std::string str)
{
	std::cout << std::endl;
	ShrubberyCreationForm		form(str);
	std::cout << form;
	form.beSigned(worker);
	worker.signForm(form);
	std::cout << form;
	//form.execute(worker);
	std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
	worker.executeForm(form);
	return ;
}

void	robotomy_sign_form(Bureaucrat worker, std::string str)
{
	std::cout << std::endl;
	RobotomyRequestForm		form(str);
	std::cout << form;
	form.beSigned(worker);
	worker.signForm(form);
	std::cout << form;
	//form.execute(worker);
	std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
	worker.executeForm(form);
	return ;
}

void	presidential_sign_form(Bureaucrat worker, std::string str)
{
	std::cout << std::endl;
	PresidentialPardonForm		form(str);
	std::cout << form;
	form.beSigned(worker);
	worker.signForm(form);
	std::cout << form;
	//form.execute(worker);
	std::cout << "BUREAUCRAT WILL EXECUTE..." << std::endl;
	worker.executeForm(form);
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
	Bureaucrat	worker_7(std::string("Normal scope"), 138);
	Bureaucrat	worker_8(std::string("Normal scope"), 137);
	Bureaucrat	worker_9(std::string("Normal scope"), 6);

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
	shrubbery_sign_form(worker, std::string("I am out of scope"));
	shrubbery_sign_form(worker, std::string("I am out of scope"));
	shrubbery_sign_form(worker, std::string("I am out of scope"));
	shrubbery_sign_form(worker, std::string("I am out of scope"));
	shrubbery_sign_form(worker_5, std::string("I am out of scope"));
	std::cout << "---------- END OUT OF SCOPE ----------" << std::endl;
	
	shrubbery_sign_form(worker_2, std::string("I need 5 or less"));
	shrubbery_sign_form(worker_3, std::string("I am good 1"));
	shrubbery_sign_form(worker_6, std::string("I am good 5"));
	shrubbery_sign_form(worker_9, std::string("I am good 5"));
	std::cout << std::endl;
	shrubbery_sign_form(worker_3, std::string("Hello"));
	shrubbery_sign_form(worker_7, std::string("Hello"));
	shrubbery_sign_form(worker_8, std::string("Hello"));
	shrubbery_sign_form(worker_9, std::string("Hello"));
	std::cout << std::endl;
	
	robotomy_sign_form(worker_3, std::string("Hello"));
	robotomy_sign_form(worker_7, std::string("Hello"));
	robotomy_sign_form(worker_8, std::string("Hello"));
	robotomy_sign_form(worker_9, std::string("Hello"));
	std::cout << std::endl;
	presidential_sign_form(worker_3, std::string("Hello"));
	presidential_sign_form(worker_7, std::string("Hello"));
	presidential_sign_form(worker_8, std::string("Hello"));
	presidential_sign_form(worker_6, std::string("Hello"));
	presidential_sign_form(worker_9, std::string("Hello"));
	std::cout << std::endl;
	
	test_ex03(std::string("robotomy request").c_str(), std::string("Bender").c_str());
	test_ex03(NULL, std::string("Bender").c_str());
	test_ex03(NULL, NULL);
	return (0);
}
