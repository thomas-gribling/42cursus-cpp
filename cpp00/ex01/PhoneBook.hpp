#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		int	_index;
		int	_size;
	
	public:
		PhoneBook();
		~PhoneBook();
		int	add_contact();
		void	ft_print();
		Contact	get_contact(int i);
		int		get_size();
};

#endif