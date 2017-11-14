#ifndef LIGHTFTPCLIENTDLG_H
#define LIGHTFTPCLIENTDLG_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QDir>
#include <QStringListModel>
#include <QListWidgetItem>
namespace Ui {
class LightFtpClientDlg;
}

class LightFtpClientDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit LightFtpClientDlg(QWidget *parent = 0);
    ~LightFtpClientDlg();
void locDir();
private slots:
    void  deleBtn_clicked();
    void  renameBtn_clicked();
private:
    Ui::LightFtpClientDlg *ui;
    QListWidget *locList;
    QListWidget *remoteList;
    QPushButton *connectBtn;
    QPushButton *disConnectBtn;
    QPushButton *deleteBtn;
    QPushButton *renameBtn;
    QLabel *clientLab;
    QLabel *serverLab;
    QLabel *ipAddrLab;
    QLineEdit *pathEdit;
    QString InitPath = "D:";
};

#endif // LIGHTFTPCLIENTDLG_H
