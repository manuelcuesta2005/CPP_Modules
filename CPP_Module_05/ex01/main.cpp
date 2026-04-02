#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "--- TEST 1: Creación y firma exitosa ---" << std::endl;
    try {
        Bureaucrat jefe("Boss", 1);
        Form contrato("Contrato de Alquiler", 50, 25);
        
        std::cout << jefe;     // Prueba operator<< de Bureaucrat
        std::cout << contrato << std::endl; // Prueba operator<< de Form

        jefe.signForm(contrato);
        std::cout << contrato << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Fallo por grado insuficiente ---" << std::endl;
    try {
        Bureaucrat becario("Intern", 140);
        Form confidencial("Documento Ultra Secreto", 5, 1);
        
        std::cout << becario;
        std::cout << confidencial << std::endl;

        becario.signForm(confidencial); // Esto debería imprimir el mensaje de error "couldn't sign"
        std::cout << confidencial << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Excepciones en constructor (Grado muy alto) ---" << std::endl;
    try {
        Form ilegal("Formulario Ilegal", 0, 50); // El grado 0 no existe
    } catch (std::exception &e) {
        std::cerr << "Excepción capturada correctamente: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Excepciones en constructor (Grado muy bajo) ---" << std::endl;
    try {
        Bureaucrat inutil("Lazy", 151); // El grado 151 no existe
    } catch (std::exception &e) {
        std::cerr << "Excepción capturada correctamente: " << e.what() << std::endl;
    }

    return 0;
}