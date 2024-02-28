#ifndef		ARRAY_HPP
# define	ARRAY_HPP
#include <cstddef>
#include <exception>
template <typename T>
class	Array
{

public:
	Array<T>(Array<T> const & src);
	Array<T>(size_t nb_elements);

    size_t const&   size()  const;

	Array<T>&	operator=(Array const& rhs);
    T&          operator[](size_t pos);
    T const&    operator[](size_t pos) const;

	Array<T>(void);
	~Array<T>(void);

private:
    T*              content;
    size_t const    _size;

    class OutOfBoundsException : public std::exception
    {
        char const* what() const throw();
    };

};

#endif
