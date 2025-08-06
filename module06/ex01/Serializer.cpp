#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
    return res;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data* res = reinterpret_cast<Data *>(raw);
	return res;
}