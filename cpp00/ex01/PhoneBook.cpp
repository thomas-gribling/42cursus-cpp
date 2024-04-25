#include "main.hpp"

PhoneBook::PhoneBook() {

}

PhoneBook::~PhoneBook() {

}

int	PhoneBook::add_contact() {
	Contact	cont;
	std::string	field[5];

	std::cout << "To add a contact, please provide the following informations\nFirst name: ";
	getline(std::cin, field[0]);
	if (field[0].empty())
		return 1;
	std::cout << "Last name: ";
	getline(std::cin, field[1]);
	if (field[1].empty())
		return 1;
	std::cout << "Nickname: ";
	getline(std::cin, field[2]);
	if (field[2].empty())
		return 1;
	std::cout << "Phone number: ";
	getline(std::cin, field[3]);
	if (field[3].empty())
		return 1;
	std::cout << "Their darkest secret (I promise I won't share): ";
	getline(std::cin, field[4]);
	if (field[4].empty())
		return 1;
	cont.set_contact(field);
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
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << "|" << std::setw(10);
			std::cout << i;
			curr = contacts[i].get_first_name();
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << curr;
			curr = contacts[i].get_last_name();
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << curr;
			curr = contacts[i].get_nickname();
			if (curr.length() > 10) {
				curr.resize(9);
				curr.resize(10, '.');
			}
			std::cout << "|" << std::setw(10);
			std::cout << curr;
			std::cout << "|" << std::endl;
		}
	}
}

Contact	PhoneBook::get_contact(int index) {
	return (contacts[index]);
}

int		PhoneBook::get_size() {
	return (size);
}