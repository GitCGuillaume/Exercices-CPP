/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchopin <gchopin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:30:12 by gchopin           #+#    #+#             */
/*   Updated: 2021/11/10 11:31:34 by gchopin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Cure : public AMateria
{
	private:
		std::string	type;

	public:
		Cure();
		virtual ~Cure(void);
		Cure(const Cure & src);
		Cure & operator=(const Cure &src);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
