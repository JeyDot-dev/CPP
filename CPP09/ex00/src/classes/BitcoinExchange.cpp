#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <string>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <iomanip>
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
void    BitcoinExchange::outputPrice(char const* file, char const c) const
{
    std::ifstream*  ifs = openFile(file);
    std::string     line;
    std::cout << std::fixed;

    while (std::getline(*ifs, line))
    {
        try
        {
            std::map<size_t, float>                     tmp = extractData(line, c);
            size_t                                      key = tmp.begin()->first;
            std::map<size_t, float>::const_iterator     l_bound = _db.lower_bound(key);
            if      (l_bound->first > key && l_bound == _db.begin())
                throw(DateNotExistException());
            else if (l_bound->first > key || l_bound == _db.end())
                l_bound--;
            std::cout << line.substr(0, line.find_first_of(" |")) 
                <<" => " << std::setprecision(4) << tmp.begin()->second <<"BTC = " <<
                std::setprecision(2) << tmp.begin()->second * l_bound->second << "$" << std::endl;
        }
        catch(DateNotExistException& e){
            std::cerr << "Error: Date does not exist: " << line << std::endl;
        }catch(BadDateFormatException& e){
            std::cerr << "Error: Bad format (prob date): " << line << std::endl;
        }catch(ValueTooLargeException& e){
            std::cerr << "Error: Value too large: " << line << std::endl;
        }catch(ValueNegativException& e){
            std::cerr << "Error: Value negative: " << line << std::endl;
        }catch(BadValueFormatException& e){
            std::cerr << "Error: Bad value format: " << line << std::endl;
        }catch(std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }
    ifs->close();
    delete ifs;
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
    float                   ret;
    size_t                  pos_start = str.find(c);

    if (pos_start == std::string::npos || ++pos_start == std::string::npos)
        throw(BadValueFormatException()); 
    pos_start = str.find_first_not_of(' ', pos_start);
    if (pos_start == std::string::npos)
        throw(BadValueFormatException());
    if (str[pos_start] == '-')
        throw(ValueNegativException());

    std::string::iterator   start = str.begin() + pos_start;
    std::string::iterator   last_char = str.end() - 1;
    if (std::count(start, str.end(), '.') > 1
            || str.find_first_not_of("01234567889.", pos_start) != std::string::npos
            ||  *last_char == '.')
        throw(BadValueFormatException());
    ret = atof(str.substr(pos_start, std::string::npos).c_str());
    if (c == '|' && ret > 1000)
        throw(ValueTooLargeException());
    return ret;
}
std::map<size_t, float>     BitcoinExchange::extractData(std::string str, char const c) const
{
    std::map<size_t, float> ret;
    size_t                  date = findDate(str, c);
    ret.insert(std::pair<size_t, float>(date, findValue(str, c)));
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
            fs->close();
            delete fs;
        }
        catch(std::exception& e)
        {
            fs->close();
            delete fs;
            throw(e);
        }
    }
    catch(std::exception &e)
    {
        std::cout << "Something wrong in data file: " << e.what() << std::endl;
        throw;
    }
}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _db(src._db)
{
}
//--------------Non-Member--------------//
