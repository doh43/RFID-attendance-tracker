#ifndef FILEWRITEBOX_H
#define FILEWRITEBOX_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>

/**
 * @brief A text box that displays the current contents of a .txt file and allows the user to update them.
 * 
 * This class provides a graphical user interface for viewing and editing the contents of a text file.
 * It includes functionalities to display the file contents, save changes, and discard changes.
 * 
 * @author Tomas Garcia
 */
class FileWriteBox : public QWidget {
    Q_OBJECT

    public:
        /**
        * @brief Constructs a FileWriteBox object.
        *
        * A FileWriteBox object is composed of a QTextEdit box , and two buttons. 
        * One of the buttons is used to save the changes made by the user using the text edit and the other one is used to discard them.
        * 
        * @param parent The parent widget.
        */
        FileWriteBox(QWidget *parent = nullptr);

        /**
        * @brief Destroys the FileWriteBox object.
        *
        * This method has been left empty.
        */
        ~FileWriteBox();

    private:
        QTextEdit *text_box;         /**< Text edit widget to display and edit the file contents. */
        QPushButton *save_button;    /**< Button to save changes to the file. */
        QPushButton *discard_button; /**< Button to discard changes and revert to the previous file contents. */

        /**
        * @brief Displays the current contents of the file in the text box.
        */
        void displayFileContent();

        /**
        * @brief Sets up the layout for the file write box.
        */
        void layoutSetup();
    
    private slots:
        /**
        * @brief Saves the changes made to the file.
        *
        * Connected to the clicked signal of the save button.
        */
        void saveToFile();

        /**
        * @brief Discards the changes made and reverts to the previous file contents.
        * 
        * Connected to the clicked signal of the discard button.
        */
        void discardChanges();
};

#endif // FILEWRITEBOX_H
