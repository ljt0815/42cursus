#ifndef CASTING_HPP
# define CASTING_HPP

# include <sstream>
# include <iostream>
# include <cstdlib>


class	Casting {
	private	:
		std::string _str;
		double	_val;
		bool	_err;

	public	:
		char	toChar(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		double	getDouble(void)	const;
		void	printChar(std::ostream &o);
		void	printInt(std::ostream &o, Casting &c);
		void	printFloat(std::ostream &o, Casting &c);
		void	printDouble(std::ostream &o, Casting &c);
		Casting(std::string str);
};
std::ostream& operator<<(std::ostream& o, Casting& c);
#endif
