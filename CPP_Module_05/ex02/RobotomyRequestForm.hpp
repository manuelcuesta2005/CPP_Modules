#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        virtual void performAction() const;
};
