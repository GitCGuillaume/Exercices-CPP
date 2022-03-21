#ifndef HUMAINB_HPP

#include <iostream>

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_weapon_type;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weapon_type);
		void	attack(void) const;
};

#endif
