#ifndef USER_WINDOW_H
#define USER_WINDOW_H
 
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QDateTime>
 
class UserWindow : public QWidget {
	Q_OBJECT
 
public:
	UserWindow(QWidget *parent = nullptr);
	~UserWindow();
 
private:
	QLabel *greetingLabel; // label that greets the user
	QLabel *timeLabel; // label that displays the login time
};
 
#endif
 
