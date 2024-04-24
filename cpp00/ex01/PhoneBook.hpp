#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		Contact	contacts[8];
		int	index = 0;
		int	size = 0;
		int	add_contact();
		void	ft_print();
};

#endif