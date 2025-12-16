#include <iostream>
#include <stdexcept>
#include <exception>

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
        Form& operator(const Form& other);
        ~Form();

        class GradeTooHighException : public std::runtime_error {
            public:
                GradeTooHighException(const std::string& message);
        }
        class GradeTooLowException : public std::runtime_error {
            public:
                GradeTooLowException(const std::string& message);
        }

        bool beSigned(const Form& form);
};
