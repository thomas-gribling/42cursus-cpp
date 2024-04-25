#include "main.hpp"

int	main() {
	std::string	line;
	int			index;
	int			isnum = 1;
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
			if (book.get_size()) {
				std::cout << "Please enter the index of the wanted contact: ";
				getline(std::cin, line);
				for (int i = 0; i < line.length() && isnum; i++)
					isnum = isdigit((int)line[i]);
				if (!isnum)
					std::cout << "Error: index must be a positive number!" << std::endl;
				else {
					index = atoi(line.c_str());
					if (index >= 0 && index < book.get_size())
						book.get_contact(index).ft_print(index);
					else
						std::cout << "Error: index out of range!" << std::endl;
				}
			}
		}
	}
	return 0;
}