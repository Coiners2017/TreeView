#include "mytab.h"

MyTab::MyTab(QWidget *parent) : QDialog(parent)
{
    tabWidget = new QTabWidget();

    //新建第一个页面的部件
    QWidget *widget = new QWidget();
    QLabel *machNameLab = new QLabel("机床名:");
    QLineEdit *machNameEdit = new QLineEdit();
    QLabel *machIDLab = new QLabel("机床ID:");
    QLineEdit *machIDEdit = new QLineEdit();
    QLabel *IPLab = new QLabel("IP:");
    QLineEdit *IPEdit = new QLineEdit();
    QLabel *FTPTypeLab = new QLabel("FTP类型:");
    QComboBox *FTPTypeComBox = new QComboBox();
    FTPTypeComBox->addItem(IDS_STRMACHFTPTYPE0);
    FTPTypeComBox->addItem(IDS_STRMACHFTPTYPE1);
    FTPTypeComBox->addItem(IDS_STRMACHFTPTYPE2);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addWidget(machNameLab);
    vLayout->addWidget(machNameEdit);
    vLayout->addWidget(machIDLab);
    vLayout->addWidget(machIDEdit);
    vLayout->addWidget(IPLab);
    vLayout->addWidget(IPEdit);
    vLayout->addWidget(FTPTypeLab);
    vLayout->addWidget(FTPTypeComBox);
    widget->setLayout(vLayout);


    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me");

    //向QTabWidget中添加第一个页面
    QIcon icon1(":/new/icon/images/1.ico");
    tabWidget->addTab(widget, icon1, "Tab1");

    //向QTabWidget中添加第二个页面
    QIcon icon2(":/new/icon/images/2.ico");
    tabWidget->addTab(label, icon2, "Tab2");

    //向QTabWidget中添加第三个页面
    QIcon icon3(":/new/icon/images/3.ico");
    tabWidget->addTab(pushButton3, icon3, "Tab3");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(tabWidget);

    this->setLayout(layout);
    this->resize(300, 100);
    this->setWindowTitle("QTabWidgetDemo");
}

