#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>

class FilledException : public std::runtime_error {
    public:
        FilledException(std::string message) : std::runtime_error(message) { }
};

class OnlyOneException : public std::runtime_error {
    public:
        OnlyOneException(std::string message) : std::runtime_error(message) { }
};

class Span {
    private:
        std::vector<int> _container;
        unsigned int _N;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        template <typename Iterator>
        void addNumber(Iterator start, Iterator end)
        {
            if (std::distance(start, end) > static_cast<long>(_N - _container.size()))
                throw FilledException("this container is full");
            _container.insert(_container.end(), start, end);
        };
        void addNumber(int number)
        {
            if (_container.size() >= _N)
                throw FilledException("this container is full");
            _container.push_back(number);
        };
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif