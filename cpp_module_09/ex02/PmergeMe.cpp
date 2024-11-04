#include "PmergeMe.hpp"

// CONSTRUCTORS - DESTRUCTORS
PmergeMe::PmergeMe() {
	_vTime = 0.0;
	_dTime = 0.0;
	_len = 0;
}

PmergeMe::PmergeMe( PmergeMe const &src ) {
	*this = src;
}

PmergeMe::~PmergeMe() {}


// OPERATORS
PmergeMe &PmergeMe::operator=( PmergeMe const &src ) {
	if (this != &src) {
		_v = src._v;
		_d = src._d;
		_vTime = src._vTime;
		_dTime = src._dTime;
		_len = src._len;
	}
	return *this;
}


// UTILS
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}


// PROGRAM
void PmergeMe::fillContainers( int ac, char **av ) {
	for (int i = 1; i < ac; i++) {
		// Check if every character is a digit
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j]))
				throw NANException();
		}
		// Check if it doesn't go over in bound
		if (std::atoll(av[i]) > std::numeric_limits<int>::max())
			throw IntException();
		// If it's all good, fill the containers
		_v.push_back(std::atoi(av[i]));
		_d.push_back(std::atoi(av[i]));
	}
	_len = ac - 1;
}

bool PmergeMe::isSorted() {
	std::vector<int>::iterator itv = _v.begin();
	int last = *itv;
	for (itv = ++itv; itv != _v.end(); itv++) {
		if (*itv < last)
			return false;
		last = *itv;
	}
	std::deque<int>::iterator itd = _d.begin();
	last = *itd;
	for (itd = ++itd; itd != _d.end(); itd++) {
		if (*itd < last)
			return false;
		last = *itd;
	}
	return true;
}

void PmergeMe::printVector() {
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayTimestamps() {
	std::cout << "Time to process a range of " << _len << " elements with std::vector : " << _vTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << _len << " elements with std::deque  : " << _dTime << " ms" << std::endl;
}

void PmergeMe::sort() {
	clock_t start1 = clock();
	sortVector(0, _v.size() - 1);
	_vTime = static_cast<double>(clock() - start1) / CLOCKS_PER_SEC * 1000;

	clock_t start2 = clock();
	sortDeque(0, _d.size());
	_dTime = static_cast<double>(clock() - start2) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::sortVector( int begin, int end ) {
	if (end - begin > 5) {
		int middle = (begin + end) / 2;
		sortVector(begin, middle);
		sortVector(middle + 1, end);
		mergeVector(begin, middle, end);
	}
	else
		insertVector(begin, end);
}

void PmergeMe::mergeVector( int begin, int middle, int end ) {
	int len1 = middle - begin + 1;
	int len2 = end - middle;
	int ri = 0;
	int li = 0;
	std::vector<int> vleft(_v.begin() + begin, _v.begin() + middle + 1);
	std::vector<int> vright(_v.begin() + middle + 1, _v.begin() + end + 1);

	for (int i = begin; i <= end; i++) {
		if (ri == len2) {
			_v[i] = vleft[li];
			li++;
		}
		else if (li == len1) {
			_v[i] = vright[ri];
			ri++;
		}
		else if (vright[ri] > vleft[li]) {
			_v[i] = vleft[li];
			li++;
		}
		else {
			_v[i] = vright[ri];
			ri++;
		}
	}
}

void PmergeMe::insertVector( int begin, int end ) {
	for (int i = begin; i < end; i++) {
		int tmp = _v[i + 1];
		int j = i + 1;
		while (j > begin && _v[j - 1] > tmp) {
			_v[j] = _v[j - 1];
			j--;
		}
		_v[j] = tmp;
	}
}

void PmergeMe::sortDeque( int begin, int end ) {
	if (end - begin > 5) {
		int middle = (begin + end) / 2;
		sortDeque(begin, middle);
		sortDeque(middle + 1, end);
		mergeDeque(begin, middle, end);
	}
	else
		insertDeque(begin, end);
}

void PmergeMe::mergeDeque( int begin, int middle, int end ) {
	int len1 = middle - begin + 1;
	int len2 = end - middle;
	int ri = 0;
	int li = 0;
	std::deque<int> dleft(_d.begin() + begin, _d.begin() + middle + 1);
	std::deque<int> dright(_d.begin() + middle + 1, _d.begin() + end + 1);

	for (int i = begin; i <= end; i++) {
		if (ri == len2) {
			_d[i] = dleft[li];
			li++;
		}
		else if (li == len1) {
			_d[i] = dright[ri];
			ri++;
		}
		else if (dright[ri] > dleft[li]) {
			_d[i] = dleft[li];
			li++;
		}
		else {
			_d[i] = dright[ri];
			ri++;
		}
	}
}

void PmergeMe::insertDeque( int begin, int end ) {
	for (int i = begin; i < end; i++) {
		int tmp = _d[i + 1];
		int j = i + 1;
		while (j > begin && _d[j - 1] > tmp) {
			_d[j] = _d[j - 1];
			j--;
		}
		_d[j] = tmp;
	}
}


// EXCEPTIONS
const char* PmergeMe::BadArgumentsException::what() const throw() {
	return "Bad arguments!\nUsage: ./PmergeMe <n1> <n2> <n3>...";
}
const char* PmergeMe::NANException::what() const throw() {
	return "Not a number!";
}
const char* PmergeMe::IntException::what() const throw() {
	return "Number above int value!";
}

const char* PmergeMe::AlreadySortedException::what() const throw() {
	return "Your numbers are already sorted!";
}
const char* PmergeMe::NotSortedException::what() const throw() {
	return "Containers aren't sorted! Give a 0 to this man!";
}