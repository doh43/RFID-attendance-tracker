#include <iostream>
#include <QApplication>
#include "../include/rfidwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    RfidWindow scan_window;
    scan_window.setWindowTitle("RFID Scanner Simulation");
    scan_window.setGeometry(100, 100, 500, 500);
    scan_window.show();

    return app.exec();
}
