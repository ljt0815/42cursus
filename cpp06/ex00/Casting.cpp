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
	if (_err)
	{
		o << "impossible" << std::endl;
		return ;
	}
	o << "char: ";
	if (getDouble() < 0 || getDouble() >= 256)
		o << "impossible" << std::endl;
	else if (getDouble() < 32 || getDouble() > 126)
		o << "Non displayable" << std::endl;
	else
		o << toChar() << std::endl;
}

void	Casting::printInt(std::ostream &o)
{
	if (_err)
	{
		o << "impossible" << std::endl;
		return ;
	}
	o << "int: ";
	o << toInt() << std::endl;
}

void	Casting::printFloat(std::ostream &o)
{
	if (_err)
	{
		o << "impossible" << std::endl;
		return ;
	}
	o << "float: ";
	if (toFloat() - toInt() == 0)
		o << toFloat() << ".0f" << std::endl;
	else
		o << toFloat() << "f" << std::endl;
}

void	Casting::printDouble(std::ostream &o)
{
	if (_err)
	{
		o << "impossible" << std::endl;
		return ;
	}
	o << "double: ";
	if (toFloat() - toInt() == 0)
		o << getDouble() << ".0" << std::endl;
	else
		o << getDouble() << std::endl;
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
	c.printInt(o);
	c.printFloat(o);
	c.printDouble(o);
	return (o);
}
