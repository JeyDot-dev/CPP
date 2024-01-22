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
//-----------------Constructors-----------------//
Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::Fixed(float const nb): _value(roundf(nb * (1 << Fixed::_nb_bits)))
{
	return ;
}

Fixed::Fixed(int const nb): _value(nb << Fixed::_nb_bits)
{
	return ;
}

Fixed::Fixed(void): _value(0)
{
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}
//-----------------Class functions and static variables-----------------//
const int	Fixed::_nb_bits = 8;

Fixed&			Fixed::min(Fixed& fna, Fixed& fnb)
{
	return fna < fnb ? fna : fnb;
}

Fixed const&	Fixed::min(Fixed const& fna, Fixed const& fnb)
{
	return fna < fnb ? fna : fnb;
}

Fixed&			Fixed::max(Fixed& fna, Fixed& fnb)
{
	return fna > fnb ? fna : fnb;
}

Fixed const&	Fixed::max(Fixed const& fna, Fixed const& fnb)
{
	return fna > fnb ? fna : fnb;
}
//-----------------Operators-----------------//
std::ostream&	operator<<(std::ostream & o, Fixed const& rhs)
{
	o << rhs.toFloat();
	return o;
}

Fixed&	Fixed::operator=(Fixed const&  rhs)
{
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

Fixed	Fixed::operator+(Fixed const& rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(Fixed const& rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return tmp;
}

Fixed	Fixed::operator*(Fixed const& rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(static_cast<int>((static_cast<long int>(this->getRawBits()) * rhs.getRawBits()) >> Fixed::_nb_bits));
	return tmp;
}

Fixed	Fixed::operator/(Fixed const& rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(static_cast<int>((static_cast<long int>(this->getRawBits() << Fixed::_nb_bits) / rhs.getRawBits())));
	return tmp;
}

bool	Fixed::operator<(Fixed const& rhs) const
{
	return this->getRawBits() < rhs.getRawBits() ? true : false;
}

bool	Fixed::operator>(Fixed const& rhs) const
{
	return this->getRawBits() > rhs.getRawBits() ? true : false;
}

bool	Fixed::operator<=(Fixed const& rhs) const
{
	return this->getRawBits() <= rhs.getRawBits() ? true : false;
}

bool	Fixed::operator>=(Fixed const& rhs) const
{
	return this->getRawBits() >= rhs.getRawBits() ? true : false;
}

bool	Fixed::operator==(Fixed const& rhs) const
{
	return this->getRawBits() == rhs.getRawBits() ? true : false;
}

bool	Fixed::operator!=(Fixed const& rhs) const
{
	return this->getRawBits() != rhs.getRawBits() ? true : false;
}
