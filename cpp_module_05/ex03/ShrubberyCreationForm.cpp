#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("MISSINGNO") {}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) : AForm("ShrubberyCreationForm", 145, 137), _target(src._target) {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeSpecial() const {
	std::ofstream of;

	of.open((_target + "_shrubbery").c_str());
	if (of.good() == false)
		throw OpenFileException();
	
	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⢤⣤⣤⣤⣤⣤⠠⣤⣤⡄⢠⣤⣤⡀⢠⣤⣤⣤⣤⠄⢠⣤⣤⣤⣤⣤⣤⡤⠀" << std::endl;
	of << "⠀⠈⢻⣿⡿⠛⠛⠀⠈⠋⣠⣾⣿⣿⣷⣄⠙⠛⠋⣡⡄⠸⣿⣿⣿⡿⠛⠛⠁⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⠿⠻⣿⣿⣿⠟⠿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠘⢋⣠⡶⠄⠙⡿⠃⠰⢦⣄⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠴⠋⠁⠀⠀⢸⣿⣇⠀⠀⠈⠛⠶⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⣴⣶⠀⣾⣿⣿⠀⢶⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣟⠁⢴⣿⣿⣿⡶⠄⠙⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠿⠓⠀⣈⢉⡁⠀⠲⠿⢿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⠿⠟⠛⠻⠿⠶⠶⠤⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⢠⣶⣶⣶⡶⠀⠀⠀⠀⠀⣶⣶⣶⣶⣾⣆⠀⠀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⣴⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀" << std::endl;
	of << "⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀⠀⢸⣿⣿⣿⡿⣿⣿⣿⣦⡀⠀⠀⠀" << std::endl;
	of << "⠀⠐⠚⠛⠛⠉⠁⠸⣿⣿⣿⠃⠀⠀⠀⠀⠀⠈⠻⣿⡏⠀⠀⠉⠙⠻⠿⣦⡀⠀" << std::endl;
	of << "⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;

	of.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &src ) {
	if (this == &src)
		return *this;
	return *this;
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw() {
	return "ShrubberyCreationForm was unable to open the file! (check permissions)";
}