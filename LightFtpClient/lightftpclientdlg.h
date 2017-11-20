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
    void deleBtn_clicked();
    void renameBtn_clicked();
    void ftpConnect();
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
    QLabel *localFileAddrLab;
    QLabel *msgTipLab;
    QLineEdit *pathEdit;
    QLineEdit *msgInfoEdit;
    QString InitPath = "D:";
};

#endif // LIGHTFTPCLIENTDLG_H
