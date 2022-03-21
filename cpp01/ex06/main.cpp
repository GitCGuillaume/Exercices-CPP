/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:37:27 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/02 14:47:19 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(int argc, char **argv)
{
	Karen	instance;
	std::string str;

	if (argc != 2)
		return (1);
	str.append(argv[1]);
	if (argc  == 2)
		instance.complain(str);
	return (0);
}
