#include "Serializer.hpp"
#include <iostream>

//--------------Functions----------------//
uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data*       Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
//--------------Operators----------------//
Serializer&	Serializer::operator=(Serializer const&  rhs)
{
	if (this != &rhs)
	{
		//copy
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
Serializer::Serializer(Serializer const &src)
{
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Serializer::Serializer(void)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Serializer::~Serializer(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
//--------------Non-Member--------------//
