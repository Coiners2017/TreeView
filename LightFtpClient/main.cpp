#include "lightftpclientdlg.h"
#include <QApplication>
#include "iptype.h"
#include "myipwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LightFtpClientDlg w;
    w.show();
    return a.exec();
}
