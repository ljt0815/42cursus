#include "C.hpp"

char C::getType(void) const
{
	return _type;
}

C::C(void) : Base()
{
	_type = 'C';
}

C::C(const C &c)
{
	_type = c.getType();
}

C &C::operator=(const C &c)
{
	if (this != &c)
	{
		_type = c.getType();
	}
	return (*this);
}

C::~C(void) {}
