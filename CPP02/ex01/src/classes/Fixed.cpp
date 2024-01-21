#include "Fixed.hpp"
//-----------------Functions-----------------//
int		Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
int		Fixed::toInt(void) const
{
	return (this->_value >> 8);
}
float	Fixed::toFloat(void) const
{
	return (this->_value / static_cast<float>((1 << Fixed::_nb_bits)));
}
//-----------------Operators-----------------//
std::ostream&	operator<<(std::ostream & o, Fixed const& rhs)
{
	o << rhs.toFloat();
	return o;
}
Fixed&	Fixed::operator=(Fixed const&  rhs)
{
	std::cout << "===Copy Operator" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}
//-----------------Constructors-----------------//
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(float const nb): _value(roundf(nb * (1 << Fixed::_nb_bits)))
{
	std::cout << "Init Float Constructor" << std::endl;
}

Fixed::Fixed(int const nb): _value(nb << Fixed::_nb_bits)
{
	std::cout << "Init Int Constructor" << std::endl;
}

Fixed::Fixed(void): _value(0)
{
	std::cout << "Constructor..." << std::endl;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor...." << std::endl;
	return ;
}
//-----------------Constants-----------------//
const int Fixed::_nb_bits = 8;
