/* A text box that displays the current contents of a txt file and allows the user to update them */
#include <iostream>
#include <QMessageBox> 
#include <QFile>
#include <QTextStream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCoreApplication>
#include "../include/filewritebox.h"

FileWriteBox::FileWriteBox(QWidget *parent) : QWidget(parent) {
    text_box = new QTextEdit(this);
    save_button = new QPushButton("Save Changes", this);
    discard_button = new QPushButton("Discard Changes", this);

    connect(save_button, &QPushButton::clicked, this, &FileWriteBox::saveToFile);
    connect(discard_button, &QPushButton::clicked, this, &FileWriteBox::discardChanges);

    displayFileContent();
    layoutSetup();
}

FileWriteBox::~FileWriteBox() {
    // EMPTY
}

void FileWriteBox::displayFileContent() {
    QFile file("emp_files/user_work.txt"); // This path is used because the app's working directory is a copy of group10 (check Dockerfile) 
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString contents = in.readAll();
        text_box->setText(contents); // Sets the text box contents to the contents of the file
        file.close();
    } 
    else {
        std::cerr << "Failed to open the file. Error code: " << file.error() << std::endl; // Outputs a file opening error to the console
    }
}

void FileWriteBox::layoutSetup() {
    // Creates a horizontal layout for the buttons
    QHBoxLayout *button_layout = new QHBoxLayout;
    button_layout->addWidget(save_button);
    button_layout->addStretch();                  // Adds stretchable space between the buttons
    button_layout->addWidget(discard_button);

    // Creates a vertical layout for the file write box
    QVBoxLayout *main_layout = new QVBoxLayout(this);
    main_layout->addWidget(text_box);
    main_layout->addLayout(button_layout);       // Adds the button layout to the main layout

    // Sets the main layout for the file write box
    this->setLayout(main_layout);
}

void FileWriteBox::saveToFile() {
    QString text = text_box->toPlainText();

    // Writes the content of text_box to the user_work file
    QFile file("emp_files/user_work.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    } 
    else {
        std::cerr << "Failed to open the file. Error code: " << file.error() << std::endl;
    }

    QMessageBox::information(this, "Success", "Your changes have been saved."); // Notifies the user that the content was written to the file

    displayFileContent(); // Displays the updated content of the user_work file in the text box
}

void FileWriteBox::discardChanges() {
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to discard your changes?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        displayFileContent();
    } 
    else {
        // User clicked "No" or closed the message box, do nothing
    }
}
