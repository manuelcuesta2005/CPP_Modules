#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("Default") {
    std::cout << "Shrubbery form has been created!!" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137), _target(target) {
    std::cout << "there is a new shrubbery form!!" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target) {
    std::cout << "this copy form was created successfully" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "The Shrubbery form has been deleted!!" << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::performAction() const {
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error!!" << std::endl;
        return;
    }
    outfile << "               ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/88o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    outfile << std::endl;
    outfile.close();
    std::cout << "Se ha creado el archivo " << filename << " con exito." << std::endl;
}
