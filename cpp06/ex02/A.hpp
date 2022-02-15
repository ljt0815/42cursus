#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class	A : public Base {
	public	:
		char getType(void) const;
		A(void);
		A(const A &a);
		A &operator=(const A &a);
		virtual ~A(void);
};
#endif
