#include "main.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void	Contact::ft_print(int id) {
	std::cout << "=== ABOUT CONTACT #" << id << " ===" << std::endl;
	std::cout << "- First name:   " << first_name << std::endl;
	std::cout << "- Last name:    " << last_name << std::endl;
	std::cout << "- Nickname:     " << nickname << std::endl;
	std::cout << "- Phone:        " << phone_number << std::endl;
	std::cout << "- Their secret: " << darkest_secret << std::endl;
	std::cout << "========================" << std::endl;
}