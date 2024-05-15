#include "Harl.hpp"

void	Harl::debug( void ) {
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl << std::endl;

}

void	Harl::complain( std::string level ) {
	func	funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int j = -1;
	for (int i = 0; i < 4; i++) {
		if (level == names[i])
			j = i;
	}
	if (j > -1)
		(this->*funcs[j])();
	else
		std::cout << "[INVALID]\nWhat the hell is he even complaining about!?" << std::endl << std::endl;
}