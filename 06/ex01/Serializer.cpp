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

// reinterpret_castは、型安全を無視して、ポインタや整数型を別のポインタや整数型に変換します。