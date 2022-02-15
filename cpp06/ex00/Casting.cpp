#include "Casting.hpp"

char	Casting::toChar(void) const
{
	return (static_cast<char>(_val));
}

int		Casting::toInt(void) const
{
	return (static_cast<int>(_val));
}

float	Casting::toFloat(void) const
{
	return (static_cast<float>(_val));
}

double	Casting::getDouble(void) const
{
	return (_val);
}

void	Casting::printChar(std::ostream &o)
{
	if (getDouble() < 0 || getDouble() >= 256)
		o << "impossible" << std::endl;
	else if (getDouble() < 32 || getDouble() > 126)
		o << "Non displayable" << std::endl;
	else
		o << toChar() << std::endl;
}

void	Casting::printInt(std::ostream &o, Casting &c)
{
	o << c.toInt() << std::endl;
}

Casting::Casting(void)
{}

Casting::Casting(std::string str) : _err(false)
{
	const char *c = str.c_str();
	std::ostringstream ss;

	_val = atof(c);
	ss << _val;
	if (!(ss.str() == str || (ss.str() + "f") == str))
		_err = true;
}

std::ostream &operator<<(std::ostream &o, Casting &c)
{
	c.printChar(o);
	c.printInt(o, c);
	c.printFloat(o, c);
	c.printDouble(o, c);
	return (o);
}
