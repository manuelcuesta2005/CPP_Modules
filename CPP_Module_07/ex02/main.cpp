#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "--- 1. Prueba de tipos diferentes (Templates) ---" << std::endl;
    Array<int> ints(3);
    Array<std::string> strings(2);

    strings[0] = "Hola";
    strings[1] = "Mundo";

    std::cout << "Array de strings: " << strings[0] << " " << strings[1] << std::endl;
    std::cout << "Tamaño de ints: " << ints.size() << std::endl;

    std::cout << "\n--- 2. Prueba de Copia Profunda (Deep Copy) ---" << std::endl;
    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    Array<int> copia = original; // Usa operador de asignación o constructor de copia
    copia[0] = 99; // Modificamos la copia

    std::cout << "Original[0]: " << original[0] << " (debe ser 10)" << std::endl;
    std::cout << "Copia[0]:    " << copia[0] << " (debe ser 99)" << std::endl;

    if (original[0] != copia[0])
        std::cout << ">> EXITO: La copia es profunda (espacios de memoria distintos)." << std::endl;
    else
        std::cout << ">> ERROR: Copia superficial detectada." << std::endl;

    std::cout << "\n--- 3. Prueba de Excepciones ---" << std::endl;
    try {
        std::cout << "Intentando acceder a indice 10 en un array de 3..." << std::endl;
        std::cout << original[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Excepcion capturada: " << e.what() << std::endl;
    }

    std::cout << "\n--- 4. Prueba de Constancia (Solo lectura) ---" << std::endl;
    const Array<int> const_array(2);
    // const_array[0] = 5; // Si descomentas esto, no debería compilar.
    std::cout << "Acceso lectura a const_array[0]: " << const_array[0] << std::endl;

    return 0;
}