#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {
    std::cout << _name << " form constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    std::cout << _name << " is a form created successfully" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
    std::cout << _name << "copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {
    std::cout << _name << " form has been destroyed" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : std::runtime_error(message) { }

Form::GradeTooHighException::GradeTooHighException(const std::string& message) : std::runtime_error(message) { }

bool Form::beSigned(const Form& form) {
    if
}