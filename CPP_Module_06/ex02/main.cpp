#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <ctime>

Base* generate(void) {
    int base = std::rand() % 3;
        if (base == 0) {
            std::cout << "A" << std::endl;
            return (new A());
		}
		else if (base == 1) {
			std::cout << "B" << std::endl;
            return (new B());
		}
		else {
            std::cout << "C" << std::endl;
            return (new C());
		}
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) { }

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) { }

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Unknown" << std::endl;
}

int main() {
	std::srand(std::time(NULL));
	Base *test = generate();
	if (test) {
		identify(test);
		identify(*test);
		delete test;
	}
	return 0;
}