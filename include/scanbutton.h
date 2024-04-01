#ifndef SCANBUTTON_H
#define SCANBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include "adminwindow.h"
#include "userwindow.h"
#define ADMIN 1

/**
 * @brief Enumeration representing the status of the scan button.
 * 
 * This enumeration defines two status values for the scan button:
 * - checked_out: Represents the status when the account window is not open.
 * - checked_in: Represents the status when the account window is open.
 */
enum Status {
    checked_out = 0,
    checked_in = 1
};

/**
 * @brief Represents a successful RFID scan button.
 * 
 * This class provides functionality for a button that simulates an RFID scanning operation.
 * It handles left and right click events to perform check-in/check-out operations
 * and opens respective windows for admin and regular users.
 * 
 * @author Tomas Garcia
 */
class ScanButton : public QPushButton {
    Q_OBJECT

    public:
        /**
        * @brief Constructs a ScanButton object.
        * 
        * @param type_account The type of account (ADMIN or USER) that the button is simulating a scan for.
        * @param parent The parent widget.
        */
        ScanButton(int type_account, QWidget *parent = nullptr);

        /**
        * @brief Destroys the ScanButton object.
        *
        * This method has been left empty.
        */
        ~ScanButton();

    protected: 
        Status account_status;     /**< The current account status (checked_out or checked_in). */
        AdminWindow *admin_window; /**< Pointer to the admin window object. */
        UserWindow *user_window;   /**< Pointer to the user window object. */
        int account_type;          /**< The type of account (ADMIN or USER). */

    protected slots:
        /**
        * @brief Handles mouse press events.
        * 
        * @param event The mouse press event.
        */
        void mousePressEvent(QMouseEvent *event);

        /**
        * @brief Handles left click events.
        *
        * Because left clicks represent successful scans (check-ins and checkouts), this method handles all operations required to simulate it.
        */
        virtual void handleLeftClick();

        /**
        * @brief Handles right click events.
        *
        * Because right clicks represent unsuccessful scans, this method handles all operations required to simulate it.
        */
        virtual void handleRightClick();

    signals:
        /**
        * @brief Signal emitted when right clicked.
        */
        void rightClicked();

    private:
        /**
        * @brief Opens the respective account window based on the account type.
        */
        void openAccountWindow();

        /**
        * @brief Closes the respective account window based on the account type.
        */
        void closeAccountWindow();

        /**
        * @brief Updates the button color based on the account status.
        */
        void updateColor();  
};

#endif // SCANBUTTON_H
