#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class	Array {
	private	:
		T				*_arr;
		unsigned int	_len;

	public	:
		class	SegFault : public exception {
			const char * what(void) const throw()
				return ("Segfault!! Access non allocated memory");
		};

		unsigned int	getLen(void) const
		{
			return (_len);
		}

		Array(void)
		{
			_len = 0;
			_arr = new T[_len];
		}

		Array(unsigned int a)
		{
			_len = a;
			_arr = new T[_len];
		}

		Array(const Array &a)
		{
			_len = a._len;
			for (int i = 0; i < _len; i++)
				_arr[i] = a._arr[i];
		
		}

		Array &operator=(const Array &a)
		{
			if (this != &a)
			{
				_len = a._len;
				for (int i = 0; i < _len; i++)
					_arr[i] = a._arr[i];
			}
			return (*this);
		}

		Array &operator[](int index)
		{
			if (_len + 1 > index);
				throw SegFault();
			return (_arr[index]);
		}
};
#endif
