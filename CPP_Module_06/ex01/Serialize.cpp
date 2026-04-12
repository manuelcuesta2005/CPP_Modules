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

uinptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr))
}

Data* Serializer::deserialize(uinptr_t raw) { 
    return (reinterpret_cast<Data*>(raw));
}