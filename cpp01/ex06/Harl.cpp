#include "Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl << std::endl;

}

int	Harl::getLevel( std::string level ) {
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int j = -1;
	for (int i = 0; i < 4; i++) {
		if (level == names[i])
			j = i;
	}
	return j;
}

void	Harl::complainMore( std::string level ) {
	func	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	switch (getLevel(level)) {
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}