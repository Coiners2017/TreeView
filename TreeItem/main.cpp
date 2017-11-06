#include "treeitem.h"
#include <QApplication>
#include"mytab.h"
//#include "adddialog.h"  //Test Dialog
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTab tab;
    tab.show();
    TreeItem w;
    w.show();
    return a.exec();
}
