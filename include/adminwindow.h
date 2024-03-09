#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H
#include <QMainWindow>
#include "adminuser.h"

class AdminWindow : public QMainWindow {
    public:
        AdminWindow(AdminUser *admin);
        ~AdminWindow();
    protected:

    private:
        void generateReport();
};

#endif
