/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:30:12 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/10 11:28:51 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Ice : public AMateria
{
	private:
		std::string	type;

	public:
		Ice();
		virtual ~Ice(void);
		Ice(const Ice & src);
		Ice & operator=(const Ice &src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
