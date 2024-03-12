/* Represents a sucessful RFID check in */
#include <iostream>
#include "../include/scanbutton.h"

ScanButton::ScanButton(const QString &text, QWidget *parent) : QPushButton(text, parent) {
    account_status = checked_out;
    connect(this, &ScanButton::clicked, this, &ScanButton::handleLeftClick);
    connect(this, &ScanButton::rightClicked, this, &ScanButton::handleRightClick);
}

ScanButton::~ScanButton() {
    // EMPTY
}

void ScanButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        emit rightClicked();
    }
    QPushButton::mousePressEvent(event);
}

void ScanButton::openAccountWindow() {
    this->setText("CHECKED-IN");
    admin_window = new AdminWindow();
    admin_window->show();
}

void ScanButton::closeAccountWindow() {
    this->setText("ADMIN CHECK-IN");
    admin_window->closeWindow();
}

void ScanButton::handleLeftClick() {
    if (account_status == checked_out) {
        account_status = checked_in;
        openAccountWindow();
    }
    else {
        account_status = checked_out;
        closeAccountWindow();
    }
}

void ScanButton::handleRightClick() {
    if (account_status == checked_out) {
        this->setText("ERROR");
    }
    else {
        this->setText("ERROR 2");
    }
}
