#include "Array.hpp"

void	arr_int_ok(void)
{
	int	i = 0;
	Array<int>	arr(20);

	for (i = 0; i < 20; i++)
		arr[i] = i;
	for (i = 0; i < 20; i++)
		std::cout << "arr_int_ok = " << arr[i] << std::endl;
}

void	arr_cpy(void)
{
	Array<int> arr(20);
	int	i = 0;

	for (i = 0; i < 20; i++)
		arr[i] = i;
	Array<int> arr_cpy(arr);
	arr_cpy[10] = 20000;
	arr[10] = 10000;

	std::cout << "TEST CPY ARR NORMAL" << std::endl;
	for (i = 0; i < 20; i++)
		std::cout << arr[i] << std::endl;

	std::cout << "TEST CPY ARR CPY" << std::endl;
	for (i = 0; i < 20; i++)
		std::cout << arr_cpy[i] << std::endl;

	std::cout << "END TEST CPY" << std::endl;
}

void	arr_int_ko(void)
{
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
	int	i = 0;
	Array<char>	arr(20);

	for (i = 0; i < 20; i++)
		arr[i] = 65 + i;
	for (i = 0; i < 20; i++)
		std::cout << "arr_str_ok = " << arr[i] << std::endl;
}

void	arr_str_cpy(void)
{
	Array<char> arr(20);
	int	i = 0;

	for (i = 0; i < 20; i++)
		arr[i] = i + 65;
	Array<char> arr_cpy(arr);
	arr_cpy[10] = 98;
	arr[10] = 97;

	std::cout << "TEST CPY ARR NORMAL" << std::endl;
	for (i = 0; i < 20; i++)
		std::cout << arr[i] << std::endl;

	std::cout << "TEST CPY ARR CPY" << std::endl;
	for (i = 0; i < 20; i++)
		std::cout << arr_cpy[i] << std::endl;

	std::cout << "END TEST CPY" << std::endl;
}

void	arr_str_ko(void)
{
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
	int * a = new int();
	std::cout << "* a " << a[0] << std::endl;
	delete a;
	//Template array empty parameters
	Array<int> arr();
	std::cout << "Int part" << std::endl;
	arr_int_ok();
	arr_int_ko();
	arr_cpy();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Char * part" << std::endl;
	arr_str_ok();
	arr_str_ko();
	arr_str_cpy();
	return (0);
}
