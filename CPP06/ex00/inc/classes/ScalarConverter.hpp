#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>

class	ScalarConverter
{

public:
	~ScalarConverter(void);
    static void convert(std::string const & str);

private:
	ScalarConverter(ScalarConverter const & src);
	ScalarConverter&	operator=(ScalarConverter const& rhs);

	ScalarConverter(void);

};

#endif
