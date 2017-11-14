#include "mytab.h"

MyTab::MyTab(QWidget *parent) : QDialog(parent)
{
    listView = new QListView(this);
    standardItemModel = new QStandardItemModel(this);
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
    qDebug()<<"abcd";

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
    QWidget *secondWidget = new QWidget();
    QLabel *label = new QLabel("Hello Qt");
    QCheckBox *check = new QCheckBox();
    QVBoxLayout *vSecondLayout = new QVBoxLayout();
    vSecondLayout->addWidget(label);
    vSecondLayout->addWidget(check);
    secondWidget->setLayout(vSecondLayout);



    //向QTabWidget中添加第一个页面
    QIcon icon1(":/new/icon/images/1.ico");
    tabWidget->addTab(widget, icon1, "Tab1");

    //向QTabWidget中添加第二个页面
    QIcon icon2(":/new/icon/images/2.ico");
    tabWidget->addTab(secondWidget, icon2, "Tab2");

    //向QTabWidget中添加第三个页面
    QIcon icon3(":/new/icon/images/3.ico");
    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me");
    ///////////////////////////////////////////////////////////////////////
    QListView *listCtrl = new QListView(this);
    QStringList num;
        num<<QString("1")<<QString("2")<<QString("3")<<QString("4");
        QStringListModel *model = new QStringListModel(num);
        listCtrl->setModel(model);
   ///////////////////////////////////////////////////////////////////////
    tabWidget->addTab(listCtrl, icon3, "Tab3");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(tabWidget);
    //size
    this->setLayout(layout);
    this->resize(500, 300);
    machNameEdit->resize(20,50);
    this->setWindowTitle("QTabWidgetDemo");
    QString path = "C:";
    addFolder(path);
}
void MyTab::addFolder(QString path)
{

//    //判断路径是否存在
//    QDir dir(path);
//    if(!dir.exists())
//    {
//        return;
//    }
//dir.setFilter(QDir::Files|QDir::NoSymLinks);
//QFileInfoList list = dir.entryInfoList();

//int file_count = list.count();
//    if(file_count <= 0)
//    {
//        return;
//    }

//   // QStringList string_list;
//    for(int i=0; i<10; i++)
//    {
//       // QStandardItem *item = new QStandardItem(string);
//        QFileInfo fileIinfo = list.at(i);
//        QString suffix = fileIinfo.suffix();
//        if(QString::compare(suffix, QString("png"), Qt::CaseInsensitive) == 0)
//        {
//            QString absolute_file_path = fileIinfo.absoluteFilePath();
//            //listView->append(absolute_file_path);
//        }
//        //standardItemModel->appendRow(item);
//    }
}
