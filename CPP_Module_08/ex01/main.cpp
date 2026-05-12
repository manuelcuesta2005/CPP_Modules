#include "Span.hpp"
#include <vector>
#include <iostream>
#include <ctime>   // Para std::time
#include <cstdlib> // Para std::srand y std::rand

int main() {
    // Inicializamos la semilla para números aleatorios
    std::srand(std::time(0));

    std::cout << "--- 1. PRUEBA DEL ENUNCIADO ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest:  " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- 2. PRUEBA MASIVA (20,000 números) ---" << std::endl;
    try {
        unsigned int tam = 20000;
        Span bigSpan(tam);
        std::vector<int> randomNumbers;

        for (unsigned int i = 0; i < tam; ++i) {
            randomNumbers.push_back(std::rand() % 1000000); // Números hasta 1M
        }

        // Usamos tu Template de Rango para llenar de golpe
        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "Shortest Masivo: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Masivo:  " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error en prueba masiva: " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. PRUEBA DE EXCEPCIONES (Llenado excesivo) ---" << std::endl;
    try {
        Span small(2);
        small.addNumber(1);
        small.addNumber(2);
        std::cout << "Intentando agregar un tercero a un Span de 2..." << std::endl;
        small.addNumber(3); // Esto debería lanzar FilledException
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada correctamente: " << e.what() << std::endl;
    }

    std::cout << "\n--- 4. PRUEBA DE EXCEPCIONES (Sin números suficientes) ---" << std::endl;
    try {
        Span empty(10);
        empty.addNumber(42);
        std::cout << "Intentando calcular span con solo 1 número..." << std::endl;
        empty.shortestSpan(); // Esto debería lanzar OnlyOneException
    } catch (const std::exception& e) {
        std::cout << "Excepción capturada correctamente: " << e.what() << std::endl;
    }

    return 0;
}