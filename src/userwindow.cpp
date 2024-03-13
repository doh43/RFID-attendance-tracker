/* Represents the window that opens when a regular user logs in */
 
#include "../include/userwindow.h"
 
UserWindow::UserWindow(QWidget *parent):
	QWidget(parent) {
		setWindowTitle("User Window");
    	setFixedSize(800, 600);
    	greetingLabel = new QLabel("Hello *name*", this); // creates a label that will welcome the user
    	QFont greetingFont = greetingLabel->font();
    	greetingFont.setPointSize(32);
    	greetingLabel->setFont(greetingFont);
    	greetingLabel->setAlignment(Qt::AlignCenter);
 
    	// creates a label for the time
    	QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss AP");
    	QString labelText = QString("You have logged in at <b>%1</b>").arg(currentTime);
    	timeLabel = new QLabel(labelText, this);
    	QFont timeFont = timeLabel->font(); // bold the time
    	timeFont.setPointSize(20);
    	timeLabel->setFont(timeFont);
    	timeLabel->setAlignment(Qt::AlignCenter);
 
    	// create vertical layout with a centered alignment
    	QVBoxLayout *layout = new QVBoxLayout(this);
    	layout->setAlignment(Qt::AlignCenter);
    	layout->addWidget(greetingLabel);
    	layout->addWidget(timeLabel);
 
    	setLayout(layout);
	}
 
	UserWindow::~UserWindow() {
 
	}
 