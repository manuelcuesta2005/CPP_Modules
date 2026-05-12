#include "Span.hpp"

Span::Span() : _N(0) { }

Span::Span(unsigned int N) : _N(N) { }

Span::Span(const Span& other) : _container(other._container), _N(other._N) { }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_N = other._N;
        this->_container = other._container;
    }
    return *this;
}

Span::~Span() { }


unsigned int Span::shortestSpan() {
    if (_container.size() == 1)
        throw OnlyOneException("Error: There is only one number in this container");
    std::sort(_container.begin(), _container.end());
    unsigned int min_distance = -1;
    for (size_t i = 0; i < _container.size() - 1; i++) {
        unsigned int dist = _container[i + 1] - _container[i];
        if (dist < min_distance)
            min_distance = dist;
    }
    return min_distance;
}

unsigned int Span::longestSpan() {
    if (_container.size() == 1)
        throw OnlyOneException("Error: There is only one number in this container");
    std::sort(_container.begin(), _container.end());
    return (_container.back() - _container.front());
}