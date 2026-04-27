#include "Serialize.hpp"
#include <iostream>

int main() {
    Data myStruct;

    myStruct.data = 1243243;
    myStruct.message = "hola muchachous";

	std::cout << "Data = " << myStruct.data << std::endl
			  << "Message = " << myStruct.message << std::endl;

	std::cout << "\n---- Serializer ----" << std::endl;
	uintptr_t raw = Serializer::serialize(&myStruct);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;
	std::cout << "\n---- Data content ----" << std::endl;
	std::cout << "Data = " << myStruct.data << std::endl
			  << "Message = " << myStruct.message << std::endl;

}