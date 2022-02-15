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
	if (!_isReal)
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
	if (!_isReal)
		o << getDouble() << ".0" << std::endl;
	else
		o << getDouble() << std::endl;
}

Casting::Casting(void)
{}

Casting::Casting(std::string str) : _err(false), _isReal(false)
{
	const char *c = str.c_str();
	std::ostringstream ss;
	bool	dotFlag = false;

	std::cout << std::setprecision(16);
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (dotFlag)
		{
			if (str[i] == '0')
				;
			else if (i == (int)str.length() - 1 && str[i] == 'f')
				;
			else
				_isReal = true;
		}
		else if (str[i] == '.')
		{
			dotFlag = true;
		}
	}
	_str = str;
	_val = atof(c);
	ss.precision(16);
	ss << _val;
	if (!_isReal)
	{
		if (atoi(c) != static_cast<int>(_val))
			_err = true;
	}
	else if (!(ss.str() == str || (ss.str() + "f") == str))
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
