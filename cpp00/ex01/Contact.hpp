#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {
	private:
		std::string first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	
	public:
		Contact();
		~Contact();
		void	ft_print(int id);
		void	set_contact(std::string field[5]);
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
};

#endif