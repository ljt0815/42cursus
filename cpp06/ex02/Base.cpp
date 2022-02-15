#include "Base.hpp"

Base::getType(void) const
{
	return (_type);
}

Base::Base(void) : _type(' ') {};

Base::Base(const Base &b)
{
	_type = b.getType();
}

Base &Base::operator=(const Base &b)
{
	if (this != &b)
	{
		_type = b.getType();
	}
	return (*this);
}

Base::~Base(void) {}
