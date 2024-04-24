#include "main.hpp"

int	main() {
	std::string	line;
	int			index;
	PhoneBook	book;

	while (line != "EXIT") {
		std::cout << "Please enter a command: ";
		getline(std::cin, line);
		if (line == "ADD") {
			if (!book.add_contact())
				std::cout << "Contact added successfully!" << std::endl;
			else
				std::cout << "Fields can't be empty!" << std::endl;
		}
		else if (line == "SEARCH") {
			book.ft_print();
			if (book.size) {
				std::cout << "Please enter the index of the wanted contact: ";
				getline(std::cin, line);
				index = atoi(line.c_str());
				if (index >= 0 && index < book.size)
					book.contacts[index].ft_print();
				else // also check if it contains non numeric
					std::cout << "Error: index out of range!" << std::endl;
			}
		}
	}
	return 0;
}