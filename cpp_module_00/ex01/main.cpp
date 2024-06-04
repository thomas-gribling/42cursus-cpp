#include "main.hpp"

int	main() {
	std::string	line;
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

			if (book.get_size()) {
				int	index = -1;
				int	check = 1;
				std::cout << "Please enter the index of the contact you want to see: " << std::flush;
				std::cin >> index;
				std::cout << index << std::endl;
				for (int i = 0; (size_t)i < line.length(); i++) {
					if (!isdigit(line[i]))
						check = 0;
				}
				if (index >= 0 && index < book.get_size()) {
					book.get_contact(index).ft_print(index);
					std::cout << std::endl;
				}
				else
					std::cout << "Error: index out of range!" << std::endl;
				std::cout << std::endl;
				std::cin.clear();
			}
		}
	}
	return 0;
}