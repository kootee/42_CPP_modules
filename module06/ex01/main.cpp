#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data originalData;
    originalData.data = 42;

    std::cout << "------------------------------------------------------------\n";
    std::cout << "Testing Serialization and Deserialization of a Data instance\n";
    std::cout << "------------------------------------------------------------\n";

    // Print the original Data object
    std::cout << "Original Data object:\n";
    std::cout << "Address: " << &originalData << "\n";
    std::cout << "Value: " << originalData.data << "\n\n";
	
    // Serialize the Data object
    std::cout << "Serializing data:\n";
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value (uintptr_t): " << serialized << "\n\n";
	
    // Deserialize the uintptr_t back to a Data object
    std::cout << "Deserializing to Data*:\n";
    Data* deserializedData = Serializer::deserialize(serialized);
	std::cout << "Result of Deserialization:\n";
    std::cout << "Address: " << deserializedData << "\n";
    std::cout << "Value: " << deserializedData->data << "\n\n";
	
    // Verify that the deserialized object is the same as the original
	std::cout << "Comparing deserialized data and original data\n";
    std::cout << "deserializedData Address	-> " << deserializedData << "\n";
    std::cout << "originalData Address		-> " << &originalData << "\n";
	if (deserializedData == &originalData)
    {
        std::cout << "Success: The deserialized object points to the same memory as the original object.\n";
    }
    else
    {
        std::cout << "Error: The deserialized object does not point to the same memory as the original object.\n";
    }
}