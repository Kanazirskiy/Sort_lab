#include "Flower.h"

/*!
	@brief Реализация, описанного в Flower.h, класса.
*/

/**
	   * @file Flower.cpp

*/
Flower::Flower() :name(""), colour(""), flavor(""), reg("")
{

}

Flower::Flower(std::string name, std::string colour, std::string flavor, std::string reg)
{
	this->name = name;
	this->colour = colour;
	this->flavor = flavor;
	this->reg = reg;
}

Flower::Flower(const Flower& other):name(other.name),colour(other.colour),flavor(other.flavor),reg(other.reg)
{

}

std::ostream& operator << (std::ostream& out, const Flower& obj)
{

	out << obj.name << " " << obj.colour << " " << obj.flavor << " " << obj.reg << '\n';
	return out;
}

bool Flower::operator >(const Flower& other)
{
	if (diff(name, other.name) < 0)
		return false;
	else if (diff(name, other.name) > 0)
		return true;
	else
	{
		if (diff(colour, other.colour) < 0)
			return false;
		else if (diff(colour, other.colour) > 0)
			return true;
		else
		{
			if (flavor == "weak")
				return false;
			else if (flavor == "medium" and other.flavor == "weak")
				return true;
			else if (flavor == "strong" and other.flavor != "strong")
				return true;
			else
				return false;
		}
	}
}

bool Flower::operator <(const Flower& other)
{
	if (diff(name, other.name) < 0)
		return true;
	else if (diff(name, other.name) > 0)
		return false;
	else
	{
		if (diff(colour, other.colour) < 0)
			return true;
		else if (diff(colour, other.colour) > 0)
			return false;
		else
		{
			if (flavor == "strong")
				return false;
			else if (flavor == "medium" and other.flavor == "strong")
				return true;
			else if (flavor == "weak" and other.flavor != "weak")
				return true;
			else
				return false;
		}
	}

}

bool Flower::operator >=(const Flower& other)
{
	if (diff(name, other.name) < 0)
		return false;
	else if (diff(name, other.name) > 0)
		return true;
	else
	{
		if (diff(colour, other.colour) < 0)
			return false;
		else if (diff(colour, other.colour) > 0)
			return true;
		else
		{
			if (flavor == "weak" and other.flavor=="weak")
				return true;
			else if (flavor == "medium" and other.flavor != "weak")
				return true;
			else if (flavor == "strong")
				return true;
			else
				return false;
		}
	}

}

bool Flower::operator <=(const Flower& other)
{
	if (diff(name, other.name) < 0)
		return true;
	else if (diff(name, other.name) > 0)
		return false;
	else
	{
		if (diff(colour, other.colour) < 0)
			return true;
		else if (diff(colour, other.colour) > 0)
			return false;
		else
		{
			if (flavor == "weak")
				return true;
			else if (flavor == "medium" and other.flavor != "weak")
				return true;
			else if (flavor == "strong" and other.flavor == "strong")
				return true;
			else
				return false;
		}
	}

}

int diff(std::string first, std::string second)
{
	for (size_t i = 0; i < first.length(); ++i)
	{
		if (first[i] - second[i] != 0)
			return first[i] - second[i];
		else if(i== first.length()-1)
			return 0;
	}
}
