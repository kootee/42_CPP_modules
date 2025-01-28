#include <iostream>
#include <unitypes.h>

class Data;

class Serializer
{
    private:
        Serializer() = default;
        virtual ~Serializer() = 0;

    public:
        uintptr_t serialize(Data *ptr);
};