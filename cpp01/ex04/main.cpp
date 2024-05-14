#include <iostream>
#include <fstream>

int	main(int ac, char **av) {
	if (ac < 4)
		std::cerr << "Not enough arguments!" << std::endl;
	if (ac > 4)
		std::cerr << "Too many arguments!" << std::endl;
	if (ac != 4)
	{
		std::cerr << "Usage: ./ft_sed <file> <to_replace> <replace_with>" << std::endl;
		return 1;
	}
	std::string	filename;
	filename.assign(av[1]);
	std::string	s[2];
	s[0].assign(av[2]);
	s[1].assign(av[3]);

	std::ifstream	infile;
	char	*buff;
	std::string	buffer;
	infile.open(filename);
	infile.read(buff, 1);
	buffer.assign(buff);
	infile.close();

	std::ofstream	outfile;
	outfile.open(filename + ".replace");
	outfile << buff;
	outfile.close();
	return 0;
}