#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {
    std::cout << _name << " form constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExecute) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
    std::cout << _name << " is a form created successfully" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute) {
    std::cout << _name << "copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << _name << " form has been destroyed" << std::endl;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : std::runtime_error(message) { }

AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : std::runtime_error(message) { }

AForm::FormIsSigned::FormIsSigned(const std::string& message) : std::runtime_error(message) { }

AForm::FormIsNotSigned::FormIsNotSigned(const std::string& message) : std::runtime_error(message) { }

void AForm::beSigned(const Bureaucrat& bure) {
    if (bure.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw GradeTooLowException("Tu grado es muy bajo para realizar esta accion");
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExecute() const {
    return _gradeExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() 
       << " | Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
       << " | Grade to sign: " << form.getGradeSign()
       << " | Grade to exec: " << form.getGradeExecute();
    return os;
}

void AForm::execute(Bureaucrat const& executor) const {
    if (_isSigned == false)
        throw FormIsNotSigned("this form has no been signed");
    else if (executor.getGrade() > _gradeExecute)
        throw GradeTooLowException("Tu grado es muy bajo para realizar esta accion");
    performAction();
}