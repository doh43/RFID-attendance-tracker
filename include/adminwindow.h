/**
 * @file adminwindow.h
 * @brief The window that shows up when the admin logs into the system
 * @author Ethan Wakefield
*/

#ifndef ADMIN_WINDOW_H
#define ADMIN_WINDOW_H
#include <QMainWindow>
#include <QGridLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include "adminuser.h"

/**
 * @class AdminWindow
 * @brief Subclass of the QMainWindow class. Shows the login/logout data of users.
*/
class AdminWindow : public QMainWindow {
    public:
        /**
         * @brief Constructor for the AdminWindow class
        */
        AdminWindow(/*AdminUser *admin*/);

        /**
         * @brief Sets up default values for the window
        */
        void setupWindow();

        /**
         * @brief Sets up the table widget for displaying the database contents.
        */
        void setupTable();

        /**
         * @brief Closes the window
        */
        void closeWindow();

        /**
         * @brief Detructor for AdminWindow class
        */
        ~AdminWindow();
        
    protected:

    private:
        QGridLayout *gridLayout;
        QTableWidget *table;
        void generateReport();
};

#endif
