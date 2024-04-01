#ifndef USERWINDOW_H
#define USERWINDOW_H
 
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QDateTime>

/**
 * @brief Represents the window that opens when a regular user logs in.
 * 
 * This class provides a graphical user interface for regular users upon login.
 * It displays a welcome message, current time, and a file writing box.
 * Users can view and update the contents of a text file through this window.
 * 
 * @author Taejun Ha
 * @author Tomas Garcia
 */ 
class UserWindow : public QWidget {
	Q_OBJECT
 
public:
	/**
     * @brief Constructs a UserWindow object.
	 * 
     * @param parent The parent widget.
     */
	UserWindow(QWidget *parent = nullptr);

	/**
     * @brief Destroys the UserWindow object.
	 *
	 * This method has been left empty.
     */
	~UserWindow();
 
private:
	QLabel *greetingLabel; /**< Label to display a welcome message. */
	QLabel *timeLabel;     /**< Label to display the current time. */
};
 
#endif // USERWINDOW_H
 