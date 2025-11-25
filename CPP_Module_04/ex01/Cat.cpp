#include "Cat.hpp"

Cat::Cat() : Animal() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
    _type = other._type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assigment copy constructor called" << std::endl;
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "MIAUUUUUU!!" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}