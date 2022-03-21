/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:26:45 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/04 11:18:16 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

A*	newA(void)
{
	return (new A());
}

B*	newB(void)
{
	return (new B());
}

C*	newC(void)
{
	return (new C());
}

Base * generate(void)
{
    try
    {
        Base *c_base = NULL;
        int rand_value;

        std::srand(time(NULL));
        rand_value = std::rand() % 3;
        if (rand_value == 0)
            c_base = dynamic_cast<Base *>(newA());
        else if (rand_value == 1)
            c_base = dynamic_cast<Base *>(newB());
        else if (rand_value == 2)
            c_base = dynamic_cast<Base *>(newC());
        return (c_base);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return (NULL);
    }
}

void Identify(Base * p)
{
    try
    {
        if (dynamic_cast<A *>(p))
            std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(p))
            std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(p))
            std::cout << "C" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Identify(Base & p)
{
	try
	{
		dynamic_cast<A&>(p);
	}
	catch (std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
		}
		catch (std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
}

int main(void)
{
    Base    *base_ptr = generate();

    Identify(base_ptr);
    Identify(*base_ptr);
    delete  base_ptr;
    return (0);
}
