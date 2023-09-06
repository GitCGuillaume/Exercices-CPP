#ifndef	WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T & a, T & b)
{
	T	tmp;

	tmp = b;
	b = a;
	a = tmp;
}

template <typename T>
T const & min(T const & one, T const & two)
{
	return ((one >= two) ? two : one);
}

template <typename T>
T const & max(T const & one, T const & two)
{
	if (one == two)
		return (two);
	else if (one >= two)
		return (one);
	else
		return (two);
	return (two);
}

#endif
