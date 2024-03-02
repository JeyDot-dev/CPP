#ifndef		BITCOINEXCHANGE_HPP
# define	BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <exception>

class	BitcoinExchange
{

public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	BitcoinExchange&	operator=(BitcoinExchange const& rhs);

    void    printMap(std::map<size_t, float> map) const;
    void    printDb() const;
    
	~BitcoinExchange(void);

private:
    std::map<size_t, float>    _db;

  //  std::map<size_t, float>     parseFile(char const* file, char const delim = '|') const;
    std::ifstream*              openFile(char const* file) const;
    float                       findValue(std::string str, char const c) const;
    size_t                      findDate(std::string const& str, char const& c) const;
    size_t                      checkStupidDate(int date) const;
    std::map<size_t, float>     extractData(std::string str, char const c) const;

    class   BadFileException : public std::exception
    {
        public: char const* what() const throw() {return "bad file";}
                BadFileException(){}
                BadFileException(std::ifstream* f){f->close(); delete f;}
    };
    class   ValueTooLargeException : public std::exception
    {
        public: char const* what() const throw() {return "value is too large";}
    };
    class   ValueNegativException : public std::exception
    {
        public: char const* what() const throw() {return "value is negative";}
    };
    class   DateNotExistException : public std::exception
    {
        public: char const* what() const throw() {return "date doesn't exist";}
    };
    class   BadDateFormatException : public std::exception
    {
        public: char const* what() const throw() {return "bad date format";}
    };
    class   BadValueFormatException : public std::exception
    {
        public: char const* what() const throw() {return "bad value format";}
    };
    class   BadDbException : public std::exception
    {
        public: char const* what() const throw() {return "bad database file";}
    };

};
#endif
