/* Represents a sucessful RFID check in */
#include <iostream>
#include <QSound>
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
        this->setText("CHECKED-IN");
        QSound::play(":/fx/correct1.wav");
        openAccountWindow();
    }
    else {
        account_status = checked_out;
        QSound::play(":/fx/correct1.wav");
        closeAccountWindow();
    }
}

void ScanButton::handleRightClick() {
    if (account_status == checked_out) {
        this->setText("ERROR");
        QSound::play(":/fx/incorrect-chime.wav");
    }
    else {
        this->setText("ERROR 2");
        QSound::play(":/fx/incorrect-chime.wav");
    }
}
