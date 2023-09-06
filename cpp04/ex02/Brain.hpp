#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
	protected:
		std::string	ideas[100];

	public:
		Brain();
		virtual ~Brain();
		Brain(Brain const & src);
		Brain &		operator=(Brain const & src);
		std::string	getIdea(unsigned int i) const;
		void		setIdea(std::string str, unsigned int i);
};

#endif
