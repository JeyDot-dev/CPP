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
    size_t              _max;
    std::vector<int>    _content;

private:
    class   LessThanTwoException : public std::exception
    {
        public: char const* what() const throw(){return "exception: less than 2 numbers";}
    };
    class   SpanFullException : public std::exception
    {
        public: char const* what() const throw(){return "exception: Span is full";}
    };
    class   IteratorErrorException : public std::exception
    {
        public: char const* what() const throw(){return "exception: your iterators sucks";}
    };
public:
    template <typename IT>
        void addNumber(IT start, IT end)
        {
            if (start == end)
                throw (IteratorErrorException());
            if (_content.size() + std::distance(start, end) > getMax())
                throw (SpanFullException());
            std::copy(start, end, std::back_inserter(_content));
        }
};
std::ostream&    operator<<(std::ostream& o, Span const& c);
#endif
