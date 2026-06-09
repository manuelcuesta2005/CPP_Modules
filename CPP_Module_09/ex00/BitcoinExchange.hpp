#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

class BitcoinExchange {
    private:
        std::map<std::string, float>    _history;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    saveCsv(void);
        bool    isDate(const std::string date);
        bool    isRealPrice(const float price);
        void    studyQuery(const std::string infile);
};

#endif