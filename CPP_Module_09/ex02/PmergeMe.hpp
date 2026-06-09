#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    private:
        std::vector<int>    _sortA;
        std::list<int>      _sortB;

        void    _sortVector(std::vector<int> vector);
        void    _sortList(std::list<int> list);
    public:
        PmergeMe(/* args */);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void    parsingData(int argc, char **argv);
        void    execute(int argc, char **argv);
};

#endif