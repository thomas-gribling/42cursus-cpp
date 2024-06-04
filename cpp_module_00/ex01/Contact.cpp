#include "main.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void	Contact::ft_print(int id) {
	std::cout << "=== ABOUT CONTACT #" << id << " ===" << std::endl;
	std::cout << "- First name:   " << _first_name << std::endl;
	std::cout << "- Last name:    " << _last_name << std::endl;
	std::cout << "- Nickname:     " << _nickname << std::endl;
	std::cout << "- Phone:        " << _phone_number << std::endl;
	std::cout << "- Their secret: " << _darkest_secret << std::endl;
	std::cout << "========================" << std::endl;
}

void	Contact::set_contact(std::string field[5]) {
	_first_name = field[0];
	_last_name = field[1];
	_nickname = field[2];
	_phone_number = field[3];
	_darkest_secret = field[4];
}

std::string	Contact::get_first_name() {
	return _first_name;
}

std::string	Contact::get_last_name() {
	return _last_name;
}

std::string	Contact::get_nickname() {
	return _nickname;
}