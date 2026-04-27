#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

int main() {
    // --- TEST 1: VECTOR ---
    std::cout << "--- Test con std::vector ---" << std::endl;
	// std::vector<int> array = { 1, 454, 2, 0, 5, 8, 11 };
	
    // --- TEST 2: LISTA ---
    std::cout << "\n--- Test con std::list ---" << std::endl;
	std::list<int> numbers;
	numbers.push_back(10);
	numbers.push_back(19);
	numbers.push_back(64);
	numbers.push_front(22);
	std::cout << "Numero encontrado: " << *easyfind(numbers, 10) << std::endl;

    // --- TEST 3: EXCEPCIONES ---
    std::cout << "\n--- Test de Excepción ---" << std::endl;
    try {
        std::cout << "Intentando encontrar el numero 0...\n" << *easyfind(numbers, 0);
    } 
    catch (const NotFoundException& e) {
        std::cout << "Atrapada: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error inesperado: " << e.what() << std::endl;
    }
    return 0;
}