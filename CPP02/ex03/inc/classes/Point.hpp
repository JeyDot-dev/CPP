#ifndef		POINTPOINT_HPP
# define	POINTPOINT_HPP
#include <iostream>
#include "Fixed.hpp"

class	Point
{

public:
	Point(Point const & src);
	Point(float const x, float const y);
	Fixed y(void) const;
	Fixed x(void) const;

	Point&	operator=(Point const& rhs);

	Point(void);
	~Point(void);
private:
	Fixed const	_x;
	Fixed const	_y;

};

#endif
