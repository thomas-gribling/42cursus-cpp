#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"

class PhoneBook {
	public:
		Contact	contacts[8];
		int	size = 0;
		int	empty = 1;
};

#endif