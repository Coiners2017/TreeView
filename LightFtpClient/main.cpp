#include "lightftpclientdlg.h"
#include <QApplication>
#include "iptype.h"
#include "myipwidget.h"
#include "clientconn.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LightFtpClientDlg w;
    ClientConn conn;
    //w.show();
    return a.exec();
}
