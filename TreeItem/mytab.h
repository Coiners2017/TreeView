#ifndef MYTAB_H
#define MYTAB_H
#include<QDialog>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include <QIcon>
#include <QComboBox>
#define IDS_STRMACHFTPTYPE0 "标准"
#define IDS_STRMACHFTPTYPE1 "三菱"
#define IDS_STRMACHFTPTYPE2 "西门子"
class MyTab : public QDialog
{
    Q_OBJECT
public:
    MyTab(QWidget *parent = 0);
signals:
public slots:
private:
    QTabWidget *tabWidget;
};

#endif // MYTAB_H
