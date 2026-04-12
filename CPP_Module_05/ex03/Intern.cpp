#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return (*this);
}

Intern::~Intern() {}

Intern::UnknownForm::UnknownForm(const std::string& message) : std::runtime_error(message) { }

static AForm* createShruberry(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

static AForm* createRobotomy(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

static AForm* createPresidential(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    const std::string Forms[] = {"Shrubbery request", "Robotomy request", "Presidential request"};
    AForm* (*functions[])(const std::string& target) = {createShruberry, createRobotomy, createPresidential};
    for (int i = 0; i <= 2; i++) {
        if (name == Forms[i]) {
            AForm* type = functions[i](target);
            std::cout << "Intern creates " << name << std::endl;
            return type;
        }
    }
    throw UnknownForm("Formulario desconocido");
}