#ifndef RFIDWINDOW_H
#define RFIDWINDOW_H

#include <QMainWindow>

/**
 * @brief Represents the RFID scanner window.
 * 
 * This class provides a simulation of an RFID scanner window.
 * It contains buttons for regular user and admin check-ins.
 * 
 * @author Tomas Garcia
 */
class RfidWindow : public QMainWindow {
    public:
        /**
        * @brief Constructs an RfidWindow object.
        * 
        * @param parent The parent widget.
        */
        RfidWindow(QWidget *parent = nullptr);

        /**
        * @brief Destroys the RfidWindow object.
        *
        * This method has been left empty.
        */
        ~RfidWindow();
};

#endif // RFIDWINDOW_H
