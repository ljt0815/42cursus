#ifndef C_HPP
# define C_HPP

#include "Base.hpp"

class	C : public Base {
	public	:
		char getType(void) const;
		C(void);
		C(const C &c);
		C &operator=(const C &c);
		virtual ~C(void);
};
#endif
