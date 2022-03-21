#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <deque>
#include <iterator>

/*
 * iterators are used for random access or sequential access, 
 * std::stack don't understand it by default
*/

/*
 ** Source : https://www.cplusplus.com/reference/stack/stack/
 ** for iterator example : template <class T, class Container = deque<T> > class stack;
 ** Container :
 ** 	Type of the internal underlying container object where the elements are stored.
 ** 	Its value_type shall be T.
 ** 	Aliased as member type stack::container_type.
*/

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		~MutantStack(){};
		MutantStack(const MutantStack<T> & src) : std::stack<T>(src)
		{
			return ;
		}
		MutantStack operator=(const MutantStack<T> & src)
		{
			*this = src;
			return (*this);
		}
		//Members types iterator
		typedef typename std::stack<T>::container_type::iterator	iterator;
		//https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/container/stack.html
		//Member objects Container c
		iterator	begin()
		{
			return (this->c.begin());
		};
		iterator	end()
		{
			return (this->c.end());
		};
};

#endif
