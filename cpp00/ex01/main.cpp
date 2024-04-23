#include "PhoneBook.hpp"
#include <iomanip>

void	add_contact(PhoneBook *book) {
	Contact	cont;

	std::cout << "To add a contact, please provide following informations\nFirst name: ";
	getline(std::cin, cont.first_name);
	std::cout << "Last name: ";
	getline(std::cin, cont.last_name);
	std::cout << "Nickname: ";
	getline(std::cin, cont.nickname);
	std::cout << "Phone number: ";
	getline(std::cin, cont.phone_number);
	std::cout << "Their darkest secret (I promise I won't share): ";
	getline(std::cin, cont.darkest_secret);
	if (book->size == 8)
		book->size = 0;
	book->contacts[book->size] = cont;
	book->size++;
	book->empty = 0;
	std::cout << "Contact added successfully!" << std::endl;
}

void	display_phonebook(PhoneBook book) {
	if (book.empty)
		std::cout << "Your Phone Book is empty! Use 'ADD' command to add some contacts." << std::endl;
	else {
		std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
		for (int i = 0; i < book.size; i++) {
			std::cout << "|" << std::setw(10);
			std::cout << i;
			std::cout << "|" << std::setw(10);
			std::cout << book.contacts[i].first_name;
			std::cout << "|" << std::setw(10);
			std::cout << book.contacts[i].last_name;
			std::cout << "|" << std::setw(10);
			std::cout << book.contacts[i].nickname;
			std::cout << "|" << std::endl;
		}
	}
}

int	main() {
	std::string	line;
	PhoneBook	book;

	while (line != "EXIT") {
		std::cout << "Please enter a command: ";
		getline(std::cin, line);
		if (line == "ADD")
			add_contact(&book);
		else if (line == "SEARCH")
			display_phonebook(book);
	}
	return 0;
}