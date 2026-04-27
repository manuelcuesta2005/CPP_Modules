#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

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
                std::cout << "Crear excepcion" << std::endl;
            _container.insert(_container.end(), begin, end);
        };
        void shortestSpan();
        void longestSpan();
};

#endif