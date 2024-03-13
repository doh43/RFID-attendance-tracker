/* Represents a sucessful RFID check in */
#include <iostream>
#include <QSound>
#include <QMessageBox>
#include "../include/scanbutton.h"

ScanButton::ScanButton(int type_account, QWidget *parent) : QPushButton(parent) {
    account_status = checked_out;
    account_type = type_account;

    if (account_type == ADMIN) {
        this->setText("ADMIN CHECK-IN");
    }
    else {
        this->setText("USER CHECK-IN");
    }

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
    if (account_type == ADMIN) {
        admin_window = new AdminWindow();
        admin_window->show();
    }
    else {
        user_window = new UserWindow();
        user_window->show();
    } 
}

void ScanButton::closeAccountWindow() {
    if (account_type == ADMIN) {
        this->setText("ADMIN CHECK-IN");
        admin_window->closeWindow();
    }
    else {
        this->setText("USER CHECK-IN");
        user_window->close();
    }
}

void ScanButton::handleLeftClick() {
    if (account_status == checked_out) {
        account_status = checked_in;
        this->setText("CHECKED-IN");
        QSound::play("../fx/correct1.wav");
        openAccountWindow();
    }
    else {
        account_status = checked_out;
        QSound::play("../fx/correct1.wav");
        closeAccountWindow();
    }
}

void ScanButton::handleRightClick() {
    if (account_status == checked_out) {
        QSound::play("../fx/incorrect-chime.wav");
        QMessageBox::warning(nullptr, "Check-In Failed", "Your card may not have permission to access this system. Otherwise, a scanning issue occurred.");
    }
    else {
        QSound::play("../fx/incorrect-chime.wav");
        QMessageBox::warning(nullptr, "Check-Out Failed", "A scanning issue occurred. Try again.");
    }
}
