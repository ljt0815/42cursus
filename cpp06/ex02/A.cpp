#include "A.hpp"

char A::getType(void) const;
{
	return _type;
}

A::A(void) : Base()
{
	_type = 'A';
}

A::A(const A &a)
{
	_type = a.getType();
}

A &A::operator=(const A &a)
{
	if (this != &a)
	{
		_type = a.getType();
	}
	return (*this);
}

A::~A(void) {}
