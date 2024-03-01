#ifndef		SPAN_HPP
# define	SPAN_HPP
#include <iostream>
#include <vector>

class	Span
{

public:
	Span(void);
    Span(size_t N);
	Span(Span const & src);
    ~Span(void);

    void    addNumber(int n);
    int     getNumber(size_t n) const;
    size_t  getMax() const;
    size_t  shortestSpan();
    size_t  longestSpan() const;

	Span&	operator=(Span const& rhs);

private:
    size_t          _max;
    std::vector<int>  _content;

    int     overflowCheck(int const&a, int const&b) const;
    class   LessThanTwoException : public std::exception
    {
        public: char const* what() const throw(){return "exception: less than 2 numbers";}
    };
    class   SpanFullException : public std::exception
    {
        public: char const* what() const throw(){return "exception: Span is full";}
    };
    class   DifferenceTooBigException : public std::exception
    {
        public: char const* what() const throw(){return "exception: difference is too big";}
    };


};
std::ostream&    operator<<(std::ostream& o, Span const& c);
#endif
