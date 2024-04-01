#ifndef FILEWRITEBOX_H
#define FILEWRITEBOX_H
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
class FileWriteBox : public QWidget {
    Q_OBJECT

    public:
        FileWriteBox(QWidget *parent = nullptr);
        ~FileWriteBox();
    protected slots:
        void saveToFile();
        void discardChanges();
    private:
        QTextEdit *text_box;
        QPushButton *save_button;
        QPushButton *discard_button;
        void displayFileContent();
        void layoutSetup();
};

#endif