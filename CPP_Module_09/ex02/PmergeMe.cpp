#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->_sortA = other._sortA;
    this->_sortB = other._sortB;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { 
    if (this != &other) {
        this->_sortA = other._sortA;
        this->_sortB = other._sortB;
    }
    return (*this);
}

PmergeMe::~PmergeMe() { }

void    PmergeMe::parsingData(int argc, char **argv) {
   	long				number;
	char*				endPtr;

	for(int i = 1; i < argc; i++)
	{
		number = std::strtol(argv[i], &endPtr, 10);
		if (*endPtr != '\0' || number < 0 || std::string(argv[i]).empty()
			|| number > INT_MAX) {
                std::cerr << "Error!!" << std::endl;
                exit(1);
            }
		_sortA.push_back(static_cast<int>(number));
        _sortB.push_back(static_cast<int>(number)); 
	} 
}

void    PmergeMe::execute(int argc, char **argv) {
    parsingData(argc, argv);
    
}