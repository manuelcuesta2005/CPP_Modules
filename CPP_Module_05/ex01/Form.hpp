#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <exception>

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExecute;

    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::runtime_error {
            public:
                GradeTooHighException(const std::string& message);
        };
        class GradeTooLowException : public std::runtime_error {
            public:
                GradeTooLowException(const std::string& message);
        };
        void beSigned(const Bureaucrat& bure);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif