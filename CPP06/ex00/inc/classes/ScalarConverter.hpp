#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP
#include <iostream>

class	ScalarConverter
{

public:
	ScalarConverter(ScalarConverter const & src);
	ScalarConverter&	operator=(ScalarConverter const& rhs);

	ScalarConverter(void);
	~ScalarConverter(void);

private:

};

#endif
