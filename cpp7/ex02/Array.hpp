#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
	private:
		T *	_arr;
		unsigned int	_size;
	
	public:
		Array()
		{
				this->_arr = new T[0]();
				this->_size = 0;
		};
		Array(unsigned int n)
		{
			this->_arr = new T[n]();
			this->_size = n;
		};
		~Array()
		{
			if (this->_arr)
				delete[] this->_arr;
		};
		unsigned int	size(void) const
		{
			return (this->_size);
		};
		Array(Array const & src)
		{
			this->_arr = new T[src.size()]();
			for (unsigned int i = 0; i < src.size(); i++)
				this->_arr[i] = src._arr[i];
			this->_size = src.size();
			return ;
		};
		Array & operator=(Array const & src)
		{
			if (this->_arr)
				delete this->_arr;
			this->_arr = new T[src.size()]();
			for (unsigned int i = 0; i < src.size(); i++)
				this->_arr[i] = src._arr[i];
			this->_size = src.size();
			return (*this);
		};
		/*
		** lvalue is array
		** Try catch doesn't work properly on the return value so I'm doing it a little dirty.
		*/
		T &	operator[](unsigned int idx)
		{
				if (!this->_arr)
					throw std::exception();
				if (this->size() <= idx || static_cast<int>(idx) < 0)
					throw std::exception();
				return (this->_arr[idx]);
		};
};

#endif
