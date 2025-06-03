#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &src)
{
    *this = src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
    if (this != &src)
        *this = src;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

// reinterpret_cast is used to convert a pointer to an integer type and vice versa.
// uintptr_t is an unsigned integer type that is capable of holding a pointer.
// This is useful for serialization and deserialization of pointers, allowing you to store pointers as integers and retrieve them later.