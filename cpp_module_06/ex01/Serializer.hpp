#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

typedef unsigned long uintptr_t;

struct Data {
	std::string name;
	int age;
};
std::ostream& operator<<(std::ostream& os, const Data& d);

class Serializer {
	private:
		Serializer();
		Serializer( Serializer const &src );
		~Serializer();

		Serializer &operator=( Serializer const &src );
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP