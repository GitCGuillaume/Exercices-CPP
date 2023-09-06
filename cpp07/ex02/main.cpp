#include "Array.hpp"
#include <iostream>

void	arr_int_ok(void)
{
	try
	{
		unsigned	i = 0;
		Array<int>	arr(5);

		for (i = 0; i < 5; i++)
			arr[i] = i;
		for (i = 0; i < 5; i++)
			std::cout << "arr_int_ok = " << arr[i] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void	arr_cpy(void)
{
	try
	{
		std::cout << "\033[34m" << std::endl;
		Array<int> arr(5);
		unsigned int	i = 0;

		for (i = 0; i < 5; i++)
			arr[i] = i;
		Array<int> arr_cpy(arr);
		arr_cpy[2] = 20000;
		Array<int> arr_assignation = arr;
		arr_assignation = arr;
		arr_assignation[2] = 30000;

		std::cout << "TEST CPY ARR CPY" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr_cpy[i] << std::endl;
		std::cout << "TEST CPY ASSIGNATION" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr_assignation[i] << std::endl;
		std::cout << "TEST CPY ARR NORMAL" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr[i] << std::endl;
		std::cout << "END TEST CPY" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void	arr_int_ko(void)
{
	std::cout << "\033[37m" << std::endl;
	Array<int>	arr(20);
	try
	{
		arr[-1] = 1;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		arr[20] = 1;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		arr[21] = 1;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

/* ------------------------------------------------------ */

void	arr_str_ok(void)
{
	try
	{
		unsigned int	i = 0;
		Array<char>	arr(5);

		for (i = 0; i < 5; i++)
			arr[i] = 65 + i;
		for (i = 0; i < 5; i++)
			std::cout << "arr_str_ok = " << arr[i] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void	arr_str_cpy(void)
{
	try
	{
		std::cout << "\033[36m" << std::endl;
		Array<char> arr(5);
		unsigned int	i = 0;

		for (i = 0; i < 5; i++)
			arr[i] = i + 65;
		Array<char> arr_cpy(arr);
		arr_cpy[2] = 98;
		Array<char> arr_assignation = arr;
		arr_assignation = arr;
		arr_assignation[2] = 126;
		std::cout << "TEST STR CPY ARR CPY" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr_cpy[i] << std::endl;
		std::cout << "TEST STR ASSIGNATION ARR CPY" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr_assignation[i] << std::endl;
		std::cout << "TEST STR CPY ARR NORMAL" << std::endl;
		for (i = 0; i < 5; i++)
			std::cout << arr[i] << std::endl;
		std::cout << "END STR TEST CPY" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

void	arr_str_ko(void)
{
	std::cout << "\033[37m" << std::endl;
	Array<char>	arr(20);
	try
	{
		arr[-1] = 65;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		arr[20] = 65;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try
	{
		arr[21] = 65;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
}

int	main(void)
{
	try
	{
		int * a = new int();
		std::cout << "* a " << a[0] << std::endl;
		delete a;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}
	std::cout << "\033[32mInt part" << std::endl;
	arr_int_ok();
	arr_int_ko();
	arr_cpy();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[33mChar * part" << std::endl;
	arr_str_ok();
	arr_str_ko();
	arr_str_cpy();
	std::cout << "\033[37m" << std::endl;
	return (0);
}
