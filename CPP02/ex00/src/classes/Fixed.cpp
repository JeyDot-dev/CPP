#include "Fixed.hpp"

int		Fixed::getRawBits(void) const
{
	std::cout << "Get Rawbits()" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Set Rawbits(): " << raw << std::endl;
	this->_value = raw;
}

Fixed&	Fixed::operator=(Fixed const&  rhs)
{
	std::cout << "===Copy Operator" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const nb): _value(nb)
{
	std::cout << "Init Constructor" << std::endl;
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

const int Fixed::_nb_bits = 8;
