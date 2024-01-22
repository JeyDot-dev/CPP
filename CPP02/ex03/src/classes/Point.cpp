#include "Point.hpp"

//--------------Functions----------------//
/*float const	Point::get_y(void) const
{
	return this->_y.toFloat();
}

float const	Point::get_y(void) const
{
	return this->_y.toFloat();
}*/
Fixed Point::y(void) const
{
	return this->_y;
}

Fixed Point::x(void) const
{
	return this->_x;
}
//--------------Operators----------------//
Point&	Point::operator=(Point const&  rhs)
{
	if (this != &rhs)
	{
		this->x() = rhs.x();
		this->y() = rhs.y();
	}
	return *this;
}
//--------------Constructors------------//
Point::Point(float const x, float const y): _x(x), _y(y)
{
	return ;
}

Point::Point(Point const& src): _x(src.x()), _y(src.y())
{
	return ;
}

Point::Point(void): _x(0), _y(0)
{
	return ;
}

Point::~Point(void)
{
	return ;
}
//--------------Non-Member--------------//
