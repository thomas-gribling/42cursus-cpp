#include "Base.hpp"

static unsigned int randSeed()
{
	time_t	timer;
	struct	tm	*curr_time;
	unsigned int seed;

	time(&timer);
	curr_time = localtime(&timer);
	seed = curr_time->tm_sec * curr_time->tm_min * curr_time->tm_hour * time(NULL);
	return (seed);
}

int main() {
	std::srand(randSeed()); // Better random

	Base *test = generate();

	std::cout << std::endl << "Identify from pointer:   ";
	identify(test);
	std::cout << "Identify from reference: ";
	identify(*test);

	std::cout << std::endl;
	delete test;
	return 0;
}