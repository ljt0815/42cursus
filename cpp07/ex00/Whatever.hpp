#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T a,const T b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template <typename T>
T	max(const T a, const T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
#endif
