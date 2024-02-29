#ifndef		ARRAY_HPP
# define	ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class	Array
{

public:
	Array(Array<T> const & src);
	Array(size_t nb_elements);

    size_t const&   size()  const;

	Array<T>&	operator=(Array<T> const& rhs);
    T&          operator[](size_t pos) const;

	Array(void);
	~Array(void);

private:
    size_t  _size;
    T*      _content;

    class OutOfBoundsException : public std::exception
    {
        char const* what() const throw();
    };

};
//--------------Functions----------------//
template <typename T>
size_t const&   Array<T>::size()    const
{
    return _size;
}
//--------------Operators----------------//
template <typename T>
Array<T>&	Array<T>::operator=(Array<T> const&  rhs)
{
	if (this != &rhs)
	{
        if (!this->_content || this->size() > 0)
            delete[] this->_content;
        this->_size = rhs.size();
        this->_content = new T[rhs.size()];
        for (size_t i = 0; i < rhs.size(); i++)
            (*this)[i] = rhs[i];
	}
	std::cout << "Assignation operator called (array)" << std::endl;
	return *this;
}
template <typename T>
T&          Array<T>::operator[](size_t pos) const
{
    if (pos >= size())
    {
        std::cerr << "Trying to access index: " << pos << " in array of size: " << size() << std::endl;
        throw(OutOfBoundsException());
    }
    return this->_content[pos];
}
//--------------Constructors------------//
template <typename T>
Array<T>::Array(Array<T> const &src) : _size(0), _content(NULL)
{
	*this = src;
	std::cout << "Copy constructor called (array)" << std::endl;
	return ;
}
template <typename T>
Array<T>::Array(size_t nb_elements)
{
    _size = nb_elements;
    _content = new T[_size];
}
template <typename T>
Array<T>::Array(void) : _size(0), _content(NULL)
{
	std::cout << "Default constructor called (array)" << std::endl;
	return ;
}

template <typename T>
Array<T>::~Array(void)
{
    if (this->size() > 0)
        delete[] this->_content;
    std::cout << "Destructor called (array)" << std::endl;
	return ;
}
template <typename T>
char const* Array<T>::OutOfBoundsException::what() const throw()
{
    return "exception: You should segfault lel";
}
template <typename T>
std::ostream& operator<<(std::ostream &o, Array<T> const& rhs)
{
    o << "[";
    for (size_t i = 0; i < rhs.size(); i++)
    {
        o << rhs[i];
        if (i != rhs.size() - 1)
            o << ", ";
    }
    o << "]";
    return o;
}
#endif
