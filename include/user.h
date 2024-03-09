#ifndef USER_H
#define USER_H
#include <string>
#include <chrono>
#include <ctime>

class User {
    public:
        // Constructor and Destructor
        User();
        ~User();
        
        // Getters
        std::string getLastName();
        std::string getFirstName();
        std::string getEmail();
        std::time_t getCheckinTime();
        std::time_t getCheckoutTime();

        // Setters
        void setLastName();
        void setFirstName();
        void setEmail();
        void setCheckinTime();
        void setCheckoutTime();

        // Checks Account Status
        virtual bool isAdmin();
    protected:

    private:
        std::string last_name;
        std::string first_name;
        std::string email;
        std::time_t checkin_time;
        std::time_t checkout_time;
};

#endif
