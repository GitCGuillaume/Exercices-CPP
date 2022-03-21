#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T * addr, int const & length, void (*f)(T & val))
{
	for (int i = 0; i < length; i++)
	{
		(*f)(addr[i]);
	}
}

#endif
