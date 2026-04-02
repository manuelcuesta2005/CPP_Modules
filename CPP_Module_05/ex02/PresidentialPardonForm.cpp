#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), _target("Default") {
    std::cout << "Presidential Pardon Form has been created!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5), _target(target) {
    std::cout << "there is a Presidential Pardon Form!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target) {
    std::cout << "Copy form assigned" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "The Presidential Pardon form has been deleted!!" << std::endl;
}

void PresidentialPardonForm::performAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}