#include "treeitem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TreeItem w;
    w.show();
    return a.exec();
}
