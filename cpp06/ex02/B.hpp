#ifndef B_HPP
# define B_HPP

#include "Base.hpp"

class	B : public Base {
	public	:
		char getType(void) const;
		B(void);
		B(const B &b);
		B &operator=(const B &b);
		virtual ~B(void);
}
