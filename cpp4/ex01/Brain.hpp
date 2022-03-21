#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain
{
	protected:
		std::string	ideas[100];
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const & src);
		Brain &		operator=(Brain const & src);
		void		setIdea(std::string str, int i);
		std::string	getIdea(int i) const;
};

#endif
