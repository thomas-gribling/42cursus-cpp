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

void	Contact::set_contact(std::string field[5]) {
	first_name = field[0];
	last_name = field[1];
	nickname = field[2];
	phone_number = field[3];
	darkest_secret = field[4];
}

std::string	Contact::get_first_name() {
	return first_name;
}

std::string	Contact::get_last_name() {
	return last_name;
}

std::string	Contact::get_nickname() {
	return nickname;
}