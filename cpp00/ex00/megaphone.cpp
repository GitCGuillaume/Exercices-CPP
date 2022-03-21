/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:40:48 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/11 17:19:37 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	print_str(char *str)
{
	std::string str2 = str;
	
	for (unsigned int i = 0; i < str2.length(); i++)
	{
		std::cout << (unsigned char)std::toupper(str2[i]);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (i = 1; argc > i; i++)
		print_str(argv[i]);
	std::cout << std::endl;
	return (0);
}
