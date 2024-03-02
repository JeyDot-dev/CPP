#include "Span.hpp"
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <vector>

//--------------Functions----------------//
bool    reverseSort(int a, int b);
int     Span::getNumber(size_t n) const
{
    if (n < _max)
        return _content[n];
    return 0;
}
size_t     Span::getMax() const
{
    return _max;
}
void    Span::addNumber(int n)
{
    if (this->_content.size() + 1 > this->_max)
        throw (SpanFullException());
    this->_content.push_back(n);
}

size_t  Span::shortestSpan()
{
    if (this->_content.size() <= 1)
        throw(LessThanTwoException());
    size_t span = std::numeric_limits<size_t>::max();
    std::sort(_content.begin(), _content.end(), reverseSort);
    for (size_t i = 0; i < this->_content.size() - 1; i++)
    {
        if (static_cast<size_t>(_content[i]) - _content[i + 1] < span)
            span = static_cast<size_t>(_content[i]) - _content[i + 1];
        
    }
    return span;
}
size_t  Span::longestSpan() const
{
    if (this->_content.size() <= 1)
        throw(LessThanTwoException());
    int a = *std::min_element(this->_content.begin(), this->_content.end());
    int b = *std::max_element(this->_content.begin(), this->_content.end());
    return (b - a);

}
//--------------Operators----------------//
Span&	Span::operator=(Span const&  rhs)
{
	if (this != &rhs)
	{
        this->_max = rhs._max;
        this->_content = rhs._content;
	}
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}
//--------------Constructors------------//
Span::Span(size_t N) : _max(N)
{
    std::cout << "Constructor N=" << N << std::endl;
}
Span::Span(Span const& src)
{
    *this = src;
}
Span::Span(void) : _max(0), _content(std::vector<int>())
{
}
Span::~Span(void)
{
}
//--------------Non-Member--------------//
std::ostream&   operator<<(std::ostream& o, Span const& c)
{
    o << "Span: ";
    for (size_t i = 0; i < c.getMax(); i++)
    {
        o << c.getNumber(i);
        if (i + 1 < c.getMax())
            o << ", ";
    }
    return o;
}
bool    reverseSort(int a, int b)
{
    return a > b;
}
