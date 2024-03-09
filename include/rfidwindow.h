#ifndef RFID_WINDOW_H
#define RFID_WINDOW_H
#include <QMainWindow>
#include "user.h"
#include "adminuser.h"

class RfidWindow : public QMainWindow {
    public:
        RfidWindow();
        ~RfidWindow();
    protected:

    private:
        void openAdminWindow(AdminUser *admin);
        void openUserWindow(User *user);
        void closeAdminWindow();
        void closeUserWindow();
};

#endif
