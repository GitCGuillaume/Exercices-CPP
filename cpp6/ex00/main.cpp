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
	double	value = 0;

	if (argc < 2)
		return (0);
	for (int i = 1; i < argc; i++)
	{
		convert.setString(argv[i]);
		convert.convertCharToInt();
		value = std::atof(convert.getString().c_str());
		convert.convertToChar(value);
		convert.convertToInt(value);
		convert.convertToDouble(value);
		convert.convertToFloat(value);
		convert.showValues();
	}
	return (0);
}
