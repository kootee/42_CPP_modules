#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer() = default;
        virtual ~Serializer() = 0;
		Serializer(const Serializer& other) = default;
		Serializer& operator=(const Serializer& other) = default;

    public:
        static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};