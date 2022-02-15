#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
class	Base {
	private	:
		char _type;
	public	:
		char getType(void) const;
		Base(void);
		Base(const Base &b);
		Base &operator=(const Base &b);
		virtual ~Base(void);
};
#endif
