#include "BitcoinExchange.hpp"
#include <cstddef>
#include <fstream>
#include <string>
#include <cstdlib>
#include <utility>
#include <algorithm>
//  1Value too Large, 2ValueNegative, 3DateNotExist, 4BadFormat
// BITCOIN 3 JAN 2009 ( d / 2008 > 0)
//--------------Functions----------------//
void    BitcoinExchange::printMap(std::map<size_t, float> map) const
{
    for (std::map<size_t, float>::iterator it = map.begin(); it != map.end(); it++)
        std::cout << "[" << it->first << "]:" << it->second << std::endl;
}
void    BitcoinExchange::printDb() const
{
    printMap(_db);
}
size_t  BitcoinExchange::checkStupidDate(int date) const
{
    int y, m, d;
    y = date / 10000; m = (date % 10000) / 100; d = date % 100;
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
        throw(DateNotExistException());
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
        return 0;
    if (m == 2 && d > 29)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) || d > 28)
            throw(DateNotExistException());
    }
    return date;
}
size_t  BitcoinExchange::findDate(std::string const& str, char const& c) const
{
    int         tmp;
    std::size_t ret;
    size_t pos_start = 0;
    size_t pos_final = str.find('-');
    if (pos_final == std::string::npos || pos_final != 4)
        throw(BadDateFormatException());
    tmp = std::atoi(str.substr(pos_start, pos_final).c_str()) * 10000;
                    
    pos_start = pos_final + 1;
    pos_final = str.find('-', pos_start);
    if (pos_final == std::string::npos || pos_final - pos_start != 2)
        throw(BadDateFormatException());
    tmp += std::atoi(str.substr(pos_start, pos_final).c_str()) * 100;

    pos_start = pos_final + 1;
    tmp += std::atoi(str.substr(pos_start, 2).c_str());

    pos_start += 2;
    pos_final = str.find(c, pos_start);
    ret = checkStupidDate(tmp);
    if (pos_final == std::string::npos || pos_final != str.find_first_not_of(' ', pos_final))
        throw(BadDateFormatException());
    return ret;
}
float                       BitcoinExchange::findValue(std::string str, char const c) const
{
    std::string::iterator   end = str.end();
    std::string::iterator   start;
    float                   ret;
    size_t                  pos_start = str.find(c);

    if (pos_start == std::string::npos || pos_start + 1 == std::string::npos)
        throw(BadValueFormatException()); 
    pos_start++;
    pos_start = str.find_first_not_of(' ', pos_start);
    if (pos_start == std::string::npos)
        throw(BadValueFormatException());
    start = str.begin() + pos_start;
    std::advance(end, -1);
    if (std::count(start, str.end(), '.') > 1
            || str.find_first_not_of("01234567889.", pos_start) != std::string::npos
            ||  *end == '.')
        throw(BadValueFormatException());
    ret = atof(str.substr(pos_start, std::string::npos).c_str());
    if (ret < 0)
        throw(ValueNegativException());
    if (c == '|' && ret > 1000)
        throw(ValueTooLargeException());
    return ret;
}
std::map<size_t, float>     BitcoinExchange::extractData(std::string str, char const c) const
{
    std::map<size_t, float> ret;
    ret.insert(std::pair<size_t, float>(findDate(str, c), findValue(str, c)));
    return ret;
}
std::ifstream*          BitcoinExchange::openFile(char const* file) const
{
    std::string             tmp;
    std::ifstream*          iofile = new std::ifstream(file);
    if (iofile->bad() || !std::getline(*iofile, tmp))
        throw(BadFileException(iofile));
    return iofile;
}
/*
std::map<size_t, float>    BitcoinExchange::parseFile(char const* file, char const delim) const
{
    std::ifstream*              iofile = openFile("data.csv");
    std::map<size_t, float>     map;
    std::string                 line;
    while (iofile->good())
    {
        std::getline(*iofile, line);
    }
    return map;
}*/
//--------------Operators----------------//
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const&  rhs)
{
	if (this != &rhs)
        this->_db = rhs._db;
	return *this;
}
//--------------Constructors------------//
BitcoinExchange::BitcoinExchange()
{
    try{
        std::string     line;
        std::ifstream*  fs = openFile("data.csv");
        try
        {
            while (std::getline(*fs, line))
            _db.insert(std::pair<size_t, float>(findDate(line, ','), findValue(line, ',')));
        }
        catch(std::exception& e)
        {
            fs->close();
            delete fs;
            throw(e);
        }
        fs->close();
        delete fs;
    }
    catch(std::exception &e)
    {
        std::cout << "Something wrong in data file: " << e.what() << std::endl;
        throw(BadDbException());
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _db(src._db)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "Market has collapsed (destructor)" << std::endl;
}
//--------------Non-Member--------------//
