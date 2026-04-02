#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), _target("Default") {
    std::cout << "Robotomy Form has been created!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45), _target(target) {
    std::cout << "there is a new Robotomy Form!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target) {
    std::cout << "Copy form assigned" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "The Robotomy form has been deleted!!" << std::endl;
}

void RobotomyRequestForm::performAction() const {
    int robotomy = std::rand() % 101;
    if (robotomy % 2 == 0)
    {
        std::cout << "trrr trrr trrr..." << std::endl;
        std::cout << _target << " has been robotomized" << std::endl; 
    } else
        std::cout << "The robotomy has failed" << std::endl;
}