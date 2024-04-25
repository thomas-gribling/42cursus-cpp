#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook {
	private:
		Contact	contacts[8];
		int	index = 0;
		int	size = 0;
	
	public:
		PhoneBook();
		~PhoneBook();
		int	add_contact();
		void	ft_print();
		Contact	get_contact(int index);
		int		get_size();
};

#endif