/*
 * 在进行布局设计时需要先设置Widget,然后布局需要包含Widget
 * Answer:从QT Assistant 中找到这句话：
 * Note: Creating a main window without a central widget is not supported.
 * You must have a central widget even if it is just a placeholder.
 * 所以要先 new 一个widget然后调用:
 * void setCentralWidget( QWidget* widget)
 *
*/
#include "treeitem.h"
#include "ui_treeitem.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

TreeItem::TreeItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TreeItem)
{
    ui->setupUi(this);

    QWidget *cenWidget = new QWidget(this); //this is point to QMainWindow
    setCentralWidget(cenWidget);

    treeWidget = new QTreeWidget(cenWidget);
    treeWidget ->setColumnCount(1);
    treeWidget->setHeaderLabel(tr("树形列表"));
    //treeWidget->setFixedSize(300,400);

    msgList = new QListWidget(cenWidget);
   // msgList->setFixedSize(500,200);
    msgList->addItem(new QListWidgetItem(tr("Line")));
    msgList->addItem(new QListWidgetItem(tr("Rectangle")));
    msgList->addItem(new QListWidgetItem(tr("Oval")));
    msgList->addItem(new QListWidgetItem(tr("Triangle")));

    edit = new QLineEdit(cenWidget);

    AddButton = new QPushButton(cenWidget);
    //AddButton->setGeometry(50,150,120,30); //前两个参数是位置坐标，后两个参数是按钮的尺寸。
  //  DeleteButton = new QPushButton(cenWidget);


    // 设置文本
    edit->setPlaceholderText(QStringLiteral("文本框:"));
    edit->setFixedWidth(60);
    AddButton->setText(QStringLiteral("增加"));
    AddButton->setFixedWidth(60);
  //  DeleteButton->setText(tr("删除"));
  //  DeleteButton->setFixedWidth(60);

    //设置停靠DockWidget
    dockWidget1 = new QDockWidget(this);
    dockWidget1->setFixedSize(300,500);
    dockWidget1->setWindowTitle(tr("dockwidget_tree"));
    dockWidget1->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget1->setWidget(treeWidget);

//    QVBoxLayout *buttonLayout = new QVBoxLayout(cenWidget);           //纵列
//    buttonLayout->addWidget(edit);
//    buttonLayout->addWidget(AddButton);
//    buttonLayout->addWidget(DeleteButton);


//    dockWidget2 = new QDockWidget(tr("按钮窗口"),this);
//    dockWidget2->setFixedSize(300,500);
//    dockWidget2->setWindowTitle(tr("dockwidget_button"));
//    dockWidget2->setAllowedAreas(Qt::AllDockWidgetAreas);
//    dockWidget2->setWidget(*buttonLayout);

    dockWidget3 = new QDockWidget(tr("信息窗口"),this);
    dockWidget3->setWindowTitle(tr("dockwidget_inform"));
    dockWidget3->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockWidget3->setWidget(msgList);

    this->addDockWidget(Qt::LeftDockWidgetArea,dockWidget1);
   // this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget2);
    this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget3);

    connect(AddButton, SIGNAL(clicked(bool)),this,SLOT(addParentNode()));
 // connect(DeleteButton, SIGNAL(clicked(bool)),this,SLOT(deleteItems()));
    connect(treeWidget,SIGNAL(itemPressed(QTreeWidgetItem *,int)),this,SLOT(SlotItemClicked(QTreeWidgetItem*,int)));
createActionsParent();
createActionsChild();
//addParentNode();                //初始化时添加一个根节点
    initItem=new QTreeWidgetItem(treeWidget,QStringList(QString(tr("组名1"))));
//    Nodes.append(initItem);
//    strArray.append("Hello"); //可以这样
//    strArray<<"World!"; //也可以这样
//    strArray<<"MyName"<<"is"<<"LEO";//也可以这样加上个元素
}

TreeItem::~TreeItem()
{
    delete ui;
}
void TreeItem::addParentNode()               //增加根节点
{
    QTreeWidgetItem *rootItem=new QTreeWidgetItem(treeWidget,QStringList(QString(tr("组名1"))));//添加节点
    //添加子节点
  //  Nodes.append(rootItem);
    QTreeWidgetItem *item1=new QTreeWidgetItem(rootItem,QStringList(QString("参数1")));
    rootItem->addChild(item1);
}
void TreeItem::addChildNode(QTreeWidgetItem *item)               //增加子节点 undo
{
    QTreeWidgetItem *item1=new QTreeWidgetItem(item,QStringList(QString("参数1")));
    item->addChild(item1);
}

void TreeItem::deleteItems()                //删除节点 undo
{

}
void TreeItem::createActionsParent()
{
    //创建根节点菜单、菜单项
    pop_menu = new QMenu();
    addGroupAction = new QAction(this);
    changeGroupAction = new QAction(this);
    loadAction = new QAction(this);
    deleteGroupAction = new QAction(this);

    //连接信号与槽
    connect(addGroupAction, &QAction::triggered, this, &TreeItem::addGroup);
    connect(changeGroupAction, &QAction::triggered, this, &TreeItem::changeGroup);
    connect(loadAction, &QAction::triggered, this, &TreeItem::load);
    connect(deleteGroupAction, &QAction::triggered, this, &TreeItem::deleteGroup);
}
void TreeItem::createActionsChild()
{
    //创建子节点菜单、菜单项
    pop_menu = new QMenu();
    saveParaAction = new QAction(this);
    useParaAction = new QAction(this);
    changeParaAction = new QAction(this);
    deleteMachAction = new QAction(this);

    //连接信号与槽
    connect(saveParaAction, &QAction::triggered, this, &TreeItem::savePara);
    connect(useParaAction, &QAction::triggered, this, &TreeItem::usePara);
    connect(changeParaAction, &QAction::triggered, this, &TreeItem::changePara);
    connect(deleteMachAction, &QAction::triggered, this, &TreeItem::deleteMach);
}
//主菜单响应
void TreeItem::addGroup(){
    qDebug()<<"addGroup";
    AddDialog *dialog = new AddDialog;
    connect(dialog, SIGNAL(sendData(QString)),this,SLOT(receiceData(QString)));
           dialog->show();
}
void TreeItem::changeGroup(){
    qDebug()<<"changeGroup";
}
void TreeItem::load(){
    qDebug()<<"load";
}
void TreeItem::deleteGroup(){
    qDebug()<<"deleteGroup";
}
//子菜单响应
void TreeItem::changePara(){
    qDebug()<<"changePara";
    AddDialog *dialog = new AddDialog;
    connect(dialog, SIGNAL(sendData(QString)),this,SLOT(receiceData(QString)));
           dialog->show();
}
void TreeItem::savePara(){
    qDebug()<<"savePara";
}
void TreeItem::usePara(){
    qDebug()<<"usePara";
}
void TreeItem::deleteMach(){
    qDebug()<<"deleteMach";
}
void TreeItem::SlotItemClicked(QTreeWidgetItem *item, int column)
{
    if (qApp->mouseButtons() == Qt::LeftButton)
    {
        return;
    }
    if (qApp->mouseButtons() == Qt::RightButton)
    {
        int i=0;
        while(item)
        {
            item=item->parent();
            i++;
        }
        switch(i)
        {
        case 1:
            qDebug()<<"父节点";
            pop_menu->clear();
            pop_menu->addAction(addGroupAction);
            pop_menu->addAction(changeGroupAction);
            pop_menu->addAction(loadAction);
            pop_menu->addAction(deleteGroupAction);
            addGroupAction->setText(tr("添加组"));
            changeGroupAction->setText(tr("修改组"));
            loadAction->setText(tr("导入"));
            deleteGroupAction->setText(tr("删除组"));
            //菜单出现的位置为当前鼠标的位置
            pop_menu->exec(QCursor::pos());
            //pop_menu->show();
            break;
        case 2:
            qDebug()<<"子节点";
            pop_menu->clear();
            pop_menu->addAction(saveParaAction);
            pop_menu->addAction(useParaAction);
            pop_menu->addAction(changeParaAction);
            pop_menu->addAction(deleteMachAction);
            saveParaAction->setText(tr("保存参数"));
            useParaAction->setText(tr("调用参数"));
            changeParaAction->setText(tr("修改参数"));
            deleteMachAction->setText(tr("删除节点"));
            //菜单出现的位置为当前鼠标的位置
            pop_menu->exec(QCursor::pos());
            //pop_menu->show();
            break;
        }
    }
}

void TreeItem::receiceData(QString data)
{
    receiveData = data;
    QTreeWidgetItem *item=new QTreeWidgetItem(treeWidget,QStringList(receiveData));//添加节点
    ////添加子节点
    //QTreeWidgetItem *item1=new QTreeWidgetItem(item,QStringList(receiveData));
    //item->addChild(item1);
}


/*void TreeItem::contextMenuEvent(QContextMenuEvent *event)
{
    //清除原有菜单
    QTreeWidgetItem *item = treeWidget->currentItem();
       if (item->text(0) == "fileName")
           qDebug()<<"加载自选合约页面";
    QPoint aaa = treeWidget->cursor().pos();
    pop_menu->clear();
    pop_menu->addAction(add_images_action);
    pop_menu->addAction(add_folder_action);
    pop_menu->addAction(remove_selected_action);
    pop_menu->addAction(remove_all_action);
    add_images_action->setText(tr("add images"));
    add_folder_action->setText(tr("add_folder"));
    remove_selected_action->setText(tr("remove_selected"));
    remove_all_action->setText(tr("remove_all"));
    //菜单出现的位置为当前鼠标的位置
    pop_menu->exec(QCursor::pos());
    event->accept();
}*/

//点击事件
void TreeItem::contextMenuEvent ( QContextMenuEvent * event )
{

}
void TreeItem::mouseReleaseEvent(QMouseEvent * event)
{
   // pCurrentItem = this->itemAt(event->pos());
}
