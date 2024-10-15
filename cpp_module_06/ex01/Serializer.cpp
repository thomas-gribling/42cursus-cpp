#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer( Serializer const &src ) {
	(void)src;
}

Serializer::~Serializer() {}


Serializer &Serializer::operator=( Serializer const &src ) {
	(void)src;
	return *this;
}


uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return(reinterpret_cast<Data*>(raw));
}

std::ostream& operator<<(std::ostream& os, const Data& d) {
	os << "Name: " << d.name << std::endl;
	os << "Age:  " << d.age << std::endl;
	return os;
}