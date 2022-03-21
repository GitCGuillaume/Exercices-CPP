/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:00:10 by gchopin           #+#    #+#             */
/*   Updated: 2021/10/07 16:52:03 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	main(void)
{
	Karen	instance;

	instance.complain(std::string("DEBUG"));
	instance.complain(std::string("INFO"));
	instance.complain(std::string("WARNING"));
	instance.complain(std::string("ERROR"));
	instance.complain(std::string("WRONG INPUT"));
	instance.complain(std::string("ERROR"));
	instance.complain(std::string("WARNING"));
	instance.complain(std::string("DEBUG"));
	instance.complain(std::string("INFO"));
	return (0);
}
