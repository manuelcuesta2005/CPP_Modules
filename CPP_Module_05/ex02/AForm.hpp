#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <exception>

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        void beSigned(const Bureaucrat& bure);
        const std::string& getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExecute() const;
        void execute(Bureaucrat const& executor) const;
        virtual void performAction() const = 0;

        class GradeTooHighException : public std::runtime_error {
            public:
                GradeTooHighException(const std::string& message);
        };
        class GradeTooLowException : public std::runtime_error {
            public:
                GradeTooLowException(const std::string& message);
        };
        class FormIsSigned : public std::runtime_error {
            public:
                FormIsSigned(const std::string& message);
        };
        class FormIsNotSigned : public std::runtime_error {
            public:
                FormIsNotSigned(const std::string& message);
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif