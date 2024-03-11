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
    std::cout << "ScanButton mousePressEvent called" << std::endl;
    if (event->button() == Qt::RightButton) {
        emit rightClicked();
    }
    QPushButton::mousePressEvent(event);
}

void ScanButton::handleLeftClick() {
    if (account_status == checked_out) {
        account_status = checked_in;
        this->setText("CHECKED-IN");
    }
    else {
        account_status = checked_out;
        this->setText("CHECK-IN");
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
