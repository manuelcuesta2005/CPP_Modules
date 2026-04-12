#include "Base.hpp"

Base::Base() { }

Base::Base(const Base& other) {
    (void)other;
}

Base& operator=(const Base& other) {
    (void)other;
    return *this;
}

Base::~Base() { }