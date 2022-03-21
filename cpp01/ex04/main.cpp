/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:57:08 by gchopin           #+#    #+#             */
/*   Updated: 2022/03/15 17:58:22 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool	ft_ifile_open(std::ifstream& ifs)
{
	const	bool file_open = ifs.is_open();

	if (file_open == false)
	{
		std::cerr << "Couldn't open file." << std::endl;
		return (false);
	}
	return (true);
}

bool	ft_ofile_open(std::ofstream& ofs)
{
	const	bool file_open = ofs.is_open();

	if (file_open == false)
	{
		std::cerr << "Couldn't open file." << std::endl;
		return (false);
	}
	return (true);
}

/*
 * To find occurence
 * https://www.cplusplus.com/reference/string/string/find/
*/

bool	increment_file(char **argv, std::ifstream& ifs, std::ofstream& ofs)
{
	std::string	s1, s2;
	size_t		pos_char = 0;

	s1.append(argv[2]);
	s2.append(argv[3]);
	if (s1.empty() || s2.empty() == true)
		return (true);
	while (std::getline(ifs, s1))
	{
		pos_char = s1.find(argv[2]);
		while (pos_char != std::string::npos)
		{
			if (pos_char != std::string::npos)
			{
				if (s1.compare(pos_char, std::string(argv[2]).length(), argv[2]) == 0)
				{
					s1.erase(pos_char, std::string(argv[2]).length());
					s1.insert(pos_char, s2);
				}
			}
			pos_char = s1.find(argv[2], pos_char + std::string(argv[2]).length());
		}
		ofs << s1 << std::endl;
		s1.clear();
	}
	return (false);
}

int	main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string	s1, s2;

	if (argc != 4 && (argv[1] != NULL
		|| argv[2] != NULL || argv[3] != NULL))
	{
		std::cerr << "Program must get 3 parameters." << std::endl;
		return (1);
	}
	s1.append(argv[2]);
	s2.append(argv[3]);
	if (s1.empty() || s2.empty() == true)
	{
		std::cout << "No empty parameter(s) allowed." << std::endl;
		return (1);
	}
	ifs.open(argv[1]);
	if (ft_ifile_open(ifs) == false)
		return (1);
	ofs.open((std::string(argv[1]) + std::string(".replace")).c_str(),
			std::ofstream::out | std::ofstream::trunc);
	if (ft_ofile_open(ofs) == false)
	{
		ifs.close();
		return (1);
	}
	if (increment_file(argv, ifs, ofs) == true)
		std::cout << "No empty parameter(s) allowed." << std::endl;
	ifs.close();
	ofs.close();
	return (0);
}
