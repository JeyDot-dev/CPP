#include "ScalarConverter.hpp"
#include <iomanip>

//--------------Functions----------------//
std::string impossible(int n)
{
    if (n == 1)
        return "char: impossible";
    if (n == 2)
        return impossible(1) + "\nint: impossible";
    if (n == 3)
        return impossible(2) + "\nfloat: impossible";
    if (n == 4)
        return impossible(3) + "\ndouble: impossible";
    return "";
}
void    print_result(char const& c, int const& i, float const& f, double const& d)
{
    std::cout << std::fixed << std::setprecision(1); 
    if (d > 0 && isinf(d) == false && (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max()))
        std::cout << impossible(3) << "\ndouble: " << d << std::endl;
    else if (isnan(f) || isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << impossible(2) << "\nfloat: "<< f << "f\ndouble: " << d << std::endl;
    else if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
        std::cout << impossible(1) << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
    else
    {
        std::cout << "char: ";
        if (isprint(c))
            std::cout << "\'" << c << "\'";
        else
            std::cout << "Non displayable";
        std::cout<<
            "\nint: "       << i <<
            "\nfloat: "     << f <<
            "f\ndouble: "   << d << std::endl;
    }
}
bool    weird_maths(std::string const& str)
{
    std::string const special_nums[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int i = 0;
    while (i <= 5 && str != special_nums[i])
        i++;
    if (i > 5)
        return false;
    else if (i < 3)
    {
        float f = atof(special_nums[i].c_str());
        print_result(0, 0, f, static_cast<double>(f));
    }
    else
    {
        double d = std::strtod(str.c_str(), NULL);
        print_result(0, 0, static_cast<float>(d), d);
    }
    return (true);
}
int ct_c(std::string const& str, char const& c)
{
    int ct = 0;
    int i = -1;

    while (ct < 2 && str[++i])
        if (str[i] == c) ct++;
    return ct;
}
void ScalarConverter::convert(std::string const & str)
{
    if (weird_maths(str))
        return ;
    else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') //        check if char
        print_result(str[1], static_cast<int>(str[1]), static_cast<float>(str[1]), static_cast<double>(str[1]));
    else if (isdigit(str[0]) == false)
        std::cout << impossible(4) << std::endl;
    else if (str.length() > 3 && ct_c(str, '.') == 1) //    check if floating point
    {
        if (ct_c(str, 'f') == 0)
        {
            double d = std::strtod(str.c_str(), NULL);
            print_result(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d);
        }
        else if (str.length() > 3 && ct_c(str, 'f') == 1 && str[str.length() - 1] == 'f')
        {
            float f = atof(str.c_str());
            print_result(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f));
        }
    }
    else
    {
        double d = std::strtod(str.c_str(), NULL);
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << impossible(4) << std::endl;
        else
        {
            int i = atoi(str.c_str());
            print_result(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
        }
    }
}
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//
//--------------Operators----------------//
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const&  rhs)
{
	if (this != &rhs)
	{
	}
	std::cout << "Assignation operator called (ScalarConverter)" << std::endl;
	return *this;
}
//--------------Constructors------------//
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	std::cout << "Copy constructor called (ScalarConverter)" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default constructor called (ScalarConverter)" << std::endl;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "Destructor called (ScalarConverter)" << std::endl;
	return ;
}
//--------------Non-Member--------------//
