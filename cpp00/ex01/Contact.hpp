#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {
	private:
		std::string _first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	
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