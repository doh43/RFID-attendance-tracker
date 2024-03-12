#ifndef USER_WINDOW_H
#define USER_WINDOW_H
#include <QMainWindow>
#include "user.h"

class UserWindow : public QMainWindow {
    public:
        UserWindow(User *user);
        ~UserWindow();
    protected:

    private:
        void accessResource();
};

#endif
