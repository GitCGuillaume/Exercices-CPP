/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:02:16 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/29 11:17:24 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int	main(int argc, char **argv)
{
	Convert convert;

	if (argc < 2)
		return (0);
	try
	{
		for (int i = 1; i < argc; i++)
		{
			convert.detectType(argv[i]);
			if (convert.getIsDouble() == true)
				convert.run_double(argv[i], true);
			else if (convert.getIsFloat() == true)
				convert.run_float(argv[i], true);
			else if (convert.getIsInteger() == true)
				convert.run_int(argv[i], true);
			else if (convert.getIsCharacter() == true)
				convert.run_char(argv[i], true);
			if (convert.getIsDouble() == false && convert.getIsFloat() == false &&
				convert.getIsInteger() == false && convert.getIsCharacter() == false
				&& convert.getDouble() == 0.000000 && convert.getFloat() == 0.000000
				&& convert.getInteger() == 0 && convert.getCharacter() == 0)
			{
				std::cout << "Char : Impossible" << std::endl << "Int : Impossible" << std::endl
					<< "Double : nan" << std::endl << "Float : nanf" << std::endl;
			}
			else
				convert.showValues();
			convert.setIsDouble(false);
			convert.setIsFloat(false);
			convert.setIsInteger(false);
			convert.setIsCharacter(false);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
