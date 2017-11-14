#include "lightftpclientdlg.h"
#include "ui_lightftpclientdlg.h"
#include "iptype.h"
#include "myipwidget.h"
#include <QDebug>

LightFtpClientDlg::LightFtpClientDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LightFtpClientDlg)
{
    ui->setupUi(this);
    //region 添加IPWidget DLL
    MyIPWidget *ipWidget = new MyIPWidget(this);
    try
    {
        ipWidget->settext("127.0.0.1");
        //ipWidget->show();
    }
    catch(QString exception)                      //定义异常处理，可以抓取多种类型的异常信息
    {
        QMessageBox::about(this,"Error",exception);
    }
    QWidget *pWidget = new QWidget(this);
    //listView
    locList = new QListWidget();
    remoteList = new QListWidget();
    connectBtn = new QPushButton(tr("Connect"));
    disConnectBtn = new QPushButton(tr("DisConnect"));
    deleteBtn = new QPushButton(tr("Delete"));
    renameBtn = new QPushButton(tr("Rename"));
    clientLab = new QLabel(tr("ClientList:"));
    serverLab = new QLabel(tr("ServerList:"));
    ipAddrLab = new QLabel(tr("ServerIP:"));
    pathEdit = new QLineEdit();

    setCentralWidget(pWidget);

    //Left Loyout:
    QGridLayout *leftLayout = new QGridLayout(this);
    int col_Lab = 0;
    int col_Content = 1;
    leftLayout->addWidget(clientLab,0,col_Lab);
    leftLayout->addWidget(serverLab,0,col_Content);
    leftLayout->addWidget(deleteBtn,1,col_Lab);
    leftLayout->addWidget(renameBtn,1,col_Content);
    leftLayout->addWidget(connectBtn,2,0);
    leftLayout->addWidget(disConnectBtn,2,1);
    leftLayout->addWidget(ipAddrLab,3,0);
    leftLayout->addWidget(ipWidget,3,1);
    leftLayout->addWidget(pathEdit,4,1);
    leftLayout->addWidget(locList,5,0);
    leftLayout->addWidget(remoteList,5,1);

    leftLayout->setMargin(15);
    leftLayout->setSpacing(10);
    pWidget->setLayout(leftLayout);//设置Widget窗口控件的布局风格

    locDir();
    connect(deleteBtn,SIGNAL(clicked()),this,SLOT(deleBtn_clicked()));
    connect(renameBtn, SIGNAL(clicked()),this, SLOT(renameBtn_clicked()));
}

LightFtpClientDlg::~LightFtpClientDlg()
{
    delete ui;
}
void LightFtpClientDlg::locDir()
{   
    QDir mDir("C:/Qt");
    if (!mDir.exists())
        return ;
    mDir.setFilter(QDir::Dirs|QDir::Files);
    mDir.setSorting(QDir::DirsFirst);
    qDebug() << "dir start " << mDir << "dir end";
    QStringList infolist = mDir.entryList(QDir::NoDotAndDotDot | QDir::AllEntries);//NoDotAndDotDot隐藏.和.. 避免死循环
    for(int i=0; i<infolist.size(); i++)
        //qDebug() << infolist.at(i);
        locList->addItem(infolist.at(i));
    pathEdit->setText(mDir.absolutePath());
}

void  LightFtpClientDlg::deleBtn_clicked()                  //删除listWidget所选项
{
    if(locList->currentItem()!=Q_NULLPTR)
    {
        QListWidgetItem *item = locList->takeItem(locList->currentRow());
        //删除实际文件
        QString selFileName = item->text();
        QString absPath = pathEdit->text();
        if(!absPath.endsWith("/"))absPath+="/";
        selFileName=absPath+selFileName;
        bool result = QFile::remove(selFileName);
        delete item;
    }
}

void  LightFtpClientDlg::renameBtn_clicked()                //修改listWidget所选项名称
{
    if(locList->currentItem()!=Q_NULLPTR)
    {
        locList->currentItem()->setText(tr("Modify :Item ") +QString::number(locList->count()));
    }
}
//QStringList DirFileListXml(QString xmlName,QString Path) //文件list

//{	//xmlName 文件类型 Path 路径

//    QStringList fileList;

//    QDir dir(Path);

//    if (!dir.exists()) return fileList;

//    dir.setFilter(QDir::Dirs|QDir::Files);

//    //dir.setSorting(QDir::DirsFirst);

//    dir.setSorting(QDir::Time |QDir::Reversed);

//    //排序方式 修改时间从小到大 QFileInfoList list = dir.entryInfoList();

//    int i=0,filecont=0;

//    do
//    {
//        QFileInfo fileInfo = list.at(i);

//        if(fileInfo.fileName() == "." || fileInfo.fileName()== "..")
//        {
//            qDebug()<<"filedir="<<fileInfo.fileName();

//            i++;

//            continue;

//        }
//        bool bisDir=fileInfo.isDir();

//        if(bisDir)
//        {
//        }
//        else
//        {
//            QString currentFileName=fileInfo.fileName();

//            bool Reght=currentFileName.endsWith(xmlName, Qt::CaseInsensitive);

//            if(Reght)
//            { fileList<<currentFileName;

//                qDebug()<<"filelist sort="<<currentFileName;

//                filecont++;

//            }
//        }
//        i++;

//    }
//    while(i<list.size());

//    return fileList;

//}
