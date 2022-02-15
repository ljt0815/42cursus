#ifndef CASTING_HPP
# define CASTING_HPP

# include <sstream>
# include <iostream>
# include <cstdlib>
# include <cmath>


class	Casting {
	private	:
		std::string _str;
		double	_val;
		bool	_err;
		bool	_isReal;
		Casting(void);

	public	:
		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	getDouble(void)	const;
		void	printChar(std::ostream &o);
		void	printInt(std::ostream &o);
		void	printFloat(std::ostream &o);
		void	printDouble(std::ostream &o);
		Casting(std::string str);
};
std::ostream& operator<<(std::ostream& o, Casting& c);
#endif
