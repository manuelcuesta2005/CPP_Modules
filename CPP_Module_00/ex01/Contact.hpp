#include <iostream>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    
    public:
        Contact();
        ~Contact();

        void setContact();
        void showTable(int index);
        void getContact();
        std::string truncate(const std::string &str);
};