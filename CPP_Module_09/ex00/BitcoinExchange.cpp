#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    saveCsv();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::saveCsv(void)
{
    std::ifstream csv;
    csv.open("data.csv");
    std::string line;
    std::getline(csv, line);
    while (std::getline(csv, line))
    {
        size_t position = line.find(',');
        _history[line.substr(0, position)] = std::stof(line.substr(position + 1));
    }
}

bool BitcoinExchange::isDate(const std::string date)
{
    std::string age = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (std::stoi(age) > 2022 || std::stoi(age) < 2009)
        return false;
    else if (std::stoi(month) > 12 || std::stoi(month) < 1)
        return false;
    else if (std::stoi(day) > 31 || std::stoi(day) < 1)
        return false;
    return true;
}

bool BitcoinExchange::isRealPrice(const float price)
{
    if (price > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return false;
    }
    else if (price < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::studyQuery(const std::string infile)
{
    std::ifstream input;
    input.open(infile);
    std::string line;
    std::getline(input, line);
    while (std::getline(input, line))
    {
        size_t position = line.find(" | ");
        if (position == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, position);
        std::string price = line.substr(position + 3);
        if (!isDate(date))
        {
            std::cout << "Error: bad date => " << date << std::endl;
            continue;
        }
        else if (!isRealPrice(std::stof(price)))
            continue;
        std::map<std::string, float>::iterator it = _history.lower_bound(date);
        if (it == _history.end() || it->first != date)
        {
            if (it == _history.begin())
            {
                std::cout << "Error: bad date => " << date << " (very old)" << std::endl;
                continue;
            }
            --it;
        }
        float convert = std::stof(price) * it->second;
        std::cout << date << " => " << price << " = " << convert << std::endl;
    }
}