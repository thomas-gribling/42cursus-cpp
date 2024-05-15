#include <iostream>
#include <fstream>

int	putError(std::string level, std::string fstring = "") {
	if (level == "ARGS1")
		std::cerr << "Not enough arguments!" << std::endl;
	if (level == "ARGS2")
		std::cerr << "Too many arguments!" << std::endl;
	if (level == "ARGS1" || level == "ARGS2")
		std::cerr << "Usage: ./ft_sed <file> <to_replace> <replace_with>" << std::endl;
	if (level == "FILE")
		std::cerr << "Error with file \"" << fstring << "\"!" << std::endl;
	return 1;
}

std::string	replaceLine(std::string line) { //find and replace occurences in one line
	return line;
}

int	main(int ac, char **av) {
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string	filename;
	std::string	s[2];
	std::string	buffer;

	if (ac < 4)
		return putError("ARGS1");
	if (ac > 4)
		return putError("ARGS2");

	filename.assign(av[1]);
	s[0].assign(av[2]);
	s[1].assign(av[3]);

	infile.open(filename);
	if (infile.good() == false)
		return putError("FILE", filename);
	outfile.open(filename + ".replace");
	if (outfile.good() == false)
		return infile.close(), putError("FILE", filename + ".replace");
	
	while (getline(infile, buffer))
		outfile << replaceLine(buffer) << std::endl;

	infile.close();
	outfile.close();
	return 0;
}