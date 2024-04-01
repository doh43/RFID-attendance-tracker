/* Represents the RFID scanner */
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include "../include/rfidwindow.h"
#include "../include/scanbutton.h"

RfidWindow::RfidWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("RFID Scanner Simulation");
    setGeometry(100, 100, 500, 500);

    QWidget *central_widget = new QWidget(this);

    // Sets the object name for the central widget
    central_widget->setObjectName("centerWidget");

    // Sets the background color of the central widget using a more specific CSS selector (to avoid being passed down to child widgets)
    central_widget->setStyleSheet("QWidget#centerWidget { background-color: #2B303A; }");

    setCentralWidget(central_widget);

    ScanButton *button = new ScanButton(0, this);
    ScanButton *admin_button = new ScanButton(1, this);

    QVBoxLayout *main_layout = new QVBoxLayout(central_widget);
    main_layout->addStretch(0.1);
    main_layout->addWidget(button);
    main_layout->addStretch(0.3);
    main_layout->addWidget(admin_button);
    main_layout->addStretch(0.1);

    central_widget->setLayout(main_layout);
}

RfidWindow::~RfidWindow() {
    // EMPTY
}
