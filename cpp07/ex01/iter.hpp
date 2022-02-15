#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *t, int len, void (*f)(const T &))
{
	for (int i = 0; i < len; i++)
		f(t[i]);
}
#endif
