#ifndef SCAN_BUTTON_H
#define SCAN_BUTTON_H
#include <QPushButton>
#include <QMouseEvent>
#include "adminwindow.h"
#include "userwindow.h"
#define ADMIN 1

enum Status {
    checked_out = 0,
    checked_in = 1
};

class ScanButton : public QPushButton {
    Q_OBJECT

    public:
        ScanButton(int type_account, QWidget *parent = nullptr);
        ~ScanButton();
    public slots:
        virtual void handleLeftClick();
        virtual void handleRightClick();
    protected: 
        Status account_status;
        AdminWindow *admin_window;
        UserWindow *user_window;
        int account_type;
    protected slots:
        void mousePressEvent(QMouseEvent *event);
    signals:
        void rightClicked();
    private:
        void openAccountWindow();
        void closeAccountWindow();
        void updateColor();  
};

#endif
