#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QString>
class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = 0);
    ~AddDialog();

signals:
        void findNext(const QString &str, Qt::CaseSensitivity cs);
        void findPrevious(const QString &str, Qt::CaseSensitivity cs);
void sendData(QString);
private slots:
        void findClicked();
        void enableFindButton(const QString &text);
private:
        QLabel *label;
        QLineEdit *lineEdit;
        QPushButton *findButton;
        QPushButton *closeButton;
};


#endif // ADDDIALOG_H
