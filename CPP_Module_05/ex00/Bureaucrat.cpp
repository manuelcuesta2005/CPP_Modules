#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {
    std::cout << _name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException("El grado del burocrata no puede estar por encima de su jerarquia. Tiene que estar entre 1 - 150");
    }
    if (grade > 150) {
        throw GradeTooLowException("El grado del burocrata no puede estar por debajo de su jerarquia. tiene que estar entre 150 - 1");
    }
    std::cout << _name << ", You are the new bureaucrat, congratulations!!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assigment copy constructor called" << std::endl;
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << _name << " has been destroyed" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message) : std::runtime_error(message) { }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message) : std::runtime_error(message) { }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}