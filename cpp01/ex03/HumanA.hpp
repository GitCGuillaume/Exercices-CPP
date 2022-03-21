#ifndef HUMAINA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon_type;
	public:
		HumanA(std::string name, Weapon& weapon_type);
		~HumanA(void);
		void	attack(void) const;
};

#endif
