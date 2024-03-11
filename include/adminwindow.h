#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H
#include <QMainWindow>
#include <QGridLayout>
#include <QTableWidget>
#include <QHeaderView>
#include "adminuser.h"

class AdminWindow : public QMainWindow {
    public:
        AdminWindow(/*AdminUser *admin*/);
        void setupWindow();
        void setupGrid();
        void setupTable();
        ~AdminWindow();
        
    protected:

    private:
        QGridLayout *gridLayout;
        QTableWidget *table;
        void generateReport();
};

#endif
