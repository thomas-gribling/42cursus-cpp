#include "main.hpp"

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

int	PhoneBook::add_contact() {
	Contact	cont;

	std::cout << "To add a contact, please provide following informations\nFirst name: ";
	getline(std::cin, cont.first_name);
	if (cont.first_name.empty())
		return 1;
	std::cout << "Last name: ";
	getline(std::cin, cont.last_name);
	if (cont.last_name.empty())
		return 1;
	std::cout << "Nickname: ";
	getline(std::cin, cont.nickname);
	if (cont.nickname.empty())
		return 1;
	std::cout << "Phone number: ";
	getline(std::cin, cont.phone_number);
	if (cont.phone_number.empty())
		return 1;
	std::cout << "Their darkest secret (I promise I won't share): ";
	getline(std::cin, cont.darkest_secret);
	if (cont.darkest_secret.empty())
		return 1;
	if (index == 8)
		index = 0;
	contacts[index] = cont;
	index++;
	if (size < 8)
		size++;
	return 0;
}

void	PhoneBook::ft_print() {
	std::string	curr;

	if (!size)
		std::cout << "Your Phone Book is empty! Use 'ADD' command to add some contacts." << std::endl;
	else {
		std::cout << "_____________________________________________" << std::endl;
		std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << "|" << std::setw(10);
			std::cout << std::left << i;
			curr = contacts[i].first_name;
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << std::left << curr;
			curr = contacts[i].last_name;
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << std::left << contacts[i].last_name;
			curr = contacts[i].nickname;
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << std::left << contacts[i].nickname;
			std::cout << "|" << std::endl;
		}
	}
}