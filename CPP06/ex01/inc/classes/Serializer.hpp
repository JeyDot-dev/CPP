#ifndef		SERIALIZER_HPP
# define	SERIALIZER_HPP

#include <stdint.h>

struct Data;
class	Serializer
{

public:
	~Serializer(void);
    static uintptr_t   serialize(Data* ptr);
    static Data*       deserialize(uintptr_t raw);

private:

	Serializer(Serializer const & src);
	Serializer&	operator=(Serializer const& rhs);
	Serializer(void);

};

#endif
