#include "Bureaucrat.hpp"

int main() {
    /* CREAR BUROCRATA CORRECTAMENTE */
    try {
        Bureaucrat high("Socrates", 1);
        std::cout << "New bureaucrat: " << high << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    /* CAPTURAR EXCEPCION CORRECTAMENTE */
    try {
        Bureaucrat err("El loco", 0);
        std::cout << "este burocrata esta loco, esta fuera de la jerarquia!!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception correctly: " << e.what() << std::endl;
    }
    return 0;
}