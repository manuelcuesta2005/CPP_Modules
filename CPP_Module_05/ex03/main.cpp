#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // Inicializamos la semilla para RobotomyRequestForm
    std::srand(std::time(0));

    std::cout << "--- TEST 1: El Ciclo de Vida del Shrubbery (Grados: 145, 137) ---" << std::endl;
    try {
        Bureaucrat herbert("Herbert", 140); // Puede firmar pero NO ejecutar
        ShrubberyCreationForm tree("Tree");

        std::cout << herbert;
        std::cout << tree << std::endl;

        herbert.executeForm(tree); // Fallo: No está firmado
        herbert.signForm(tree);    // Éxito: Herbert tiene grado 140 (necesita 145)
        herbert.executeForm(tree); // Fallo: Herbert tiene grado 140 (necesita 137)
        
        Bureaucrat jefe("Big Boss", 100);
        jefe.executeForm(tree);    // Éxito: Debería crear Home_shrubbery
    } catch (std::exception &e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }
    return 0;
}