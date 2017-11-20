#include "lightftpclientdlg.h"
#include "ui_lightftpclientdlg.h"
#include "iptype.h"
#include "myipwidget.h"
#include <QDebug>
#include "clientconn.h"

LightFtpClientDlg::LightFtpClientDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LightFtpClientDlg)
{
    ui->setupUi(this);
    this->resize( QSize( 800, 600 ));

    //region 添加IPWidget DLL
    MyIPWidget *ipWidget = new MyIPWidget(this);
    try
    {
        ipWidget->settext("127.0.0.1");
    }
    catch(QString exception)                      //定义异常处理，可以抓取多种类型的异常信息
    {
        QMessageBox::about(this,"Error",exception);
    }

    QWidget *pWidget = new QWidget(this);
    //listView
    locList = new QListWidget();
    remoteList = new QListWidget();
    connectBtn = new QPushButton(tr("连接"));
    connectBtn->setFixedWidth(60);
    disConnectBtn = new QPushButton(tr("断开"));
    disConnectBtn->setFixedWidth(60);
    deleteBtn = new QPushButton(tr("删除"));
    deleteBtn->setFixedWidth(60);
    renameBtn = new QPushButton(tr("重命名"));
    renameBtn->setFixedWidth(60);
    clientLab = new QLabel(tr("客户端列表:"));
    serverLab = new QLabel(tr("服务端列表:"));
    ipAddrLab = new QLabel(tr("服务端IP:"));
    localFileAddrLab = new QLabel(tr("本地文件路径:"));
    msgTipLab = new QLabel(tr("信息提示:"));
    pathEdit = new QLineEdit();
    msgInfoEdit = new QLineEdit();

    setCentralWidget(pWidget);
    QHBoxLayout *topLayout = new QHBoxLayout(this);

    topLayout->addWidget(deleteBtn,0,Qt::AlignLeft);
    topLayout->addWidget(renameBtn,0,Qt::AlignLeft);
    topLayout->addWidget(connectBtn,0,Qt::AlignLeft);
    topLayout->addWidget(disConnectBtn,0,Qt::AlignLeft);
    //Left Loyout:
    QGridLayout *leftLayout = new QGridLayout(this);
    leftLayout->addWidget(ipAddrLab,0,0);
    leftLayout->addWidget(localFileAddrLab,1,0);
    leftLayout->addWidget(clientLab,2,0);
    leftLayout->addWidget(locList,3,0);
    leftLayout->addWidget(msgTipLab,4,0);
    leftLayout->setMargin(15);
    leftLayout->setSpacing(10);

    //Right Layout:
    QGridLayout *rightLayout = new QGridLayout(this);
    rightLayout->addWidget(pathEdit,0,0);
    rightLayout->addWidget(ipWidget,1,0);
    rightLayout->addWidget(serverLab,2,0);
    rightLayout->addWidget(remoteList,3,0);
    rightLayout->addWidget(msgInfoEdit,4,0);
    rightLayout->setMargin(15);
    rightLayout->setSpacing(10);

    QHBoxLayout *bottomLayout = new QHBoxLayout(this);
    bottomLayout->addLayout(leftLayout);
    bottomLayout->addLayout(rightLayout);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);


    //mainWindow->setLayout(mainLayout);
    pWidget->setLayout(mainLayout);//设置Widget窗口控件的布局风格

    locDir();
    connect(deleteBtn,SIGNAL(clicked()),this,SLOT(deleBtn_clicked()));
    connect(renameBtn, SIGNAL(clicked()),this, SLOT(renameBtn_clicked()));
    connect(connectBtn, SIGNAL(clicked()),this, SLOT(ftpConnect()));
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
void LightFtpClientDlg::ftpConnect()
{
    ClientConn conn;
    msgInfoEdit->setText(m_msg);
}
