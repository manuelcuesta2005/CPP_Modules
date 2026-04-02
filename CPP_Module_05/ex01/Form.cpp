#include "Form.hpp"
#include "Bureaucrat.hpp"

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

void Form::beSigned(const Bureaucrat& bure) {
    if (bure.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException("Tu grado es muy bajo para realizar esta accion");
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExecute() const {
    return _gradeExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName() 
       << " | Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
       << " | Grade to sign: " << form.getGradeSign()
       << " | Grade to exec: " << form.getGradeExecute();
    return os;
}