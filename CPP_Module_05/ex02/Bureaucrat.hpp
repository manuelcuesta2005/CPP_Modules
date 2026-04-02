#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

class AForm;
class Bureaucrat
{
    private:
        const std::string _name;
        int   _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        /* 
          Esta es una forma de crear excepciones dentro de una clase personalizada 
        */
        class GradeTooHighException : public std::runtime_error{
            public:
            GradeTooHighException(const std::string& message);
        };
        class GradeTooLowException : public std::runtime_error{
            public:
            GradeTooLowException(const std::string& message);
        };

        const std::string& getName() const;
        int getGrade() const;
        void signForm(AForm& form);
        void executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif