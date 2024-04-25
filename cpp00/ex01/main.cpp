#include "main.hpp"

int	main() {
	std::string	line;
	int			index;
	PhoneBook	book;

	std::cout << "Welcome to your AMAZING PHONEBOOK!" << std::endl;
	while (line != "EXIT") {
		std::cout << "Please enter a command: ";
		getline(std::cin, line);

		if (line == "ADD") {
			std::cout << std::endl;
			if (!book.add_contact())
				std::cout << "Contact added successfully!" << std::endl;
			else
				std::cout << "Fields can't be empty!" << std::endl;
			std::cout << std::endl;
		}

		else if (line == "SEARCH") {
			std::cout << std::endl;
			book.ft_print();
			std::cout << std::endl;

			if (book.get_size()) { // just check if it's a number (atoi = 0 si pas nombre)
				std::cout << "Please enter the index of the wanted contact: ";
				getline(std::cin, line);
				index = atoi(line.c_str());
				if (index >= 0 && index < book.get_size()) {
					book.get_contact(index).ft_print(index);
					std::cout << std::endl;
				}
				else
					std::cout << "Error: invalid index!" << std::endl;
				std::cout << std::endl;
			}
		}
	}
	return 0;
}