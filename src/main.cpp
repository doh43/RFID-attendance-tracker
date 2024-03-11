#include <QApplication>
#include "./include/adminwindow.h" // change later

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    AdminWindow w;
    return app.exec();
}
