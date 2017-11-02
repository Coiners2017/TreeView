#include "treeitem.h"
#include <QApplication>
//#include "adddialog.h"  //Test Dialog
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeItem w;
    w.show();
    return a.exec();
}
