/* Represents the RFID scanner */
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include "../include/rfidwindow.h"
#include "../include/scanbutton.h"

RfidWindow::RfidWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *central_widget = new QWidget(this);
    setCentralWidget(central_widget);

    QGridLayout *grid_layout = new QGridLayout(central_widget);
    // QLabel *label = new QLabel("Scanning Station");
    // grid_layout->addWidget(label, 0, 0);

    ScanButton *button = new ScanButton(QString("CHECK-IN"), this);
    grid_layout->addWidget(button, 0, 0);

    ScanButton *admin_button = new ScanButton(QString("ADMIN CHECK-IN"), this);
    grid_layout->addWidget(admin_button, 1, 0);

    central_widget->setLayout(grid_layout);
}

RfidWindow::~RfidWindow() {
    // EMPTY
}
