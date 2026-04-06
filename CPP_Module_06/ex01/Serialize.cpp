#include "Serialize.hpp"

Serializer::Serializer() { }

Serializer::Serializer(const Serializer& other) { 
    if (this != &other)
        *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) { 
    if (this == &other)
        return *this;
    return *this;
}

Serializer::~Serializer() { }

uinptr_t Serializer::serialize(Data* ptr) { }

Data* Serializer::deserialize(uinptr_t raw) { }