#include "main.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void	Contact::ft_print() {
	std::cout << first_name << " " << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
}