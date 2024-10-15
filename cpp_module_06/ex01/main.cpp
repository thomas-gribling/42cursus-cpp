#include "Serializer.hpp"

int main() {
	Data old_data;
	old_data.name = "Pedro";
	old_data.age = 23;

	std::cout << std::endl << "=== BEFORE ===" << std::endl;
	std::cout << old_data;

	uintptr_t tmp = Serializer::serialize(&old_data);
	Data *new_data = Serializer::deserialize(tmp);

	std::cout << std::endl << "=== AFTER ===" << std::endl;
	std::cout << *new_data << std::endl;

	return 0;
}