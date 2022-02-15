#include "B.hpp"

char B::getType(void) const
{
	return _type;
}

B::B(void) : Base()
{
	_type = 'B';
}

B::B(const B &b)
{
	_type = b.getType();
}

B &B::operator=(const B &b)
{
	if (this != &b)
	{
		_type = b.getType();
	}
	return (*this);
}

B::~B(void) {}
