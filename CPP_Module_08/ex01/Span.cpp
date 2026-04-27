#include "Span.hpp"

Span::Span() : _N(0) { }

Span::Span(unsigned int N) : _N(N) { 

}

Span::Span(const Span& other) : _N(other._N), _container(other._container) { }

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_N = other._N;
    }
    return *this;
}

Span::~Span() { }
