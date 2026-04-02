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

    std::cout << "\n--- TEST 2: La Lotería de la Robotomía (Grados: 72, 45) ---" << std::endl;
    try {
        Bureaucrat bender("Bender", 40);
        RobotomyRequestForm robot("Fry");

        bender.signForm(robot);
        bender.executeForm(robot); // Éxito (50% de probabilidad de éxito real)
        bender.executeForm(robot); // Probamos de nuevo para ver el azar
    } catch (std::exception &e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: El Perdón Presidencial (Grados: 25, 5) ---" << std::endl;
    try {
        Bureaucrat ford("Ford Prefect", 20);
        Bureaucrat zaphod("Zaphod Beeblebrox", 1);
        PresidentialPardonForm pardon("Arthur Dent");

        ford.signForm(pardon);
        ford.executeForm(pardon);   // Fallo: Ford es grado 20, necesita grado 5
        zaphod.executeForm(pardon); // Éxito total
    } catch (std::exception &e) {
        std::cerr << "Excepción: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Copias y Asignaciones (Forma Canónica) ---" << std::endl;
    {
        PresidentialPardonForm original("Original");
        PresidentialPardonForm copia(original); // Prueba constructor de copia
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copia: " << copia << std::endl;
    }

    return 0;
}