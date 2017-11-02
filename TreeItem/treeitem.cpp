#include "treeitem.h"
#include "ui_treeitem.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
TreeItem::TreeItem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TreeItem)
{
    ui->setupUi(this);
    dockWidget1 = new QDockWidget(this);
    // dockWidget->setMaximumSize(300,500);
    dockWidget1->setFixedSize(300,500);
    treeWidget = new QTreeWidget;
    treeWidget ->setColumnCount(1);
    treeWidget->setHeaderLabel(tr("树形列表"));
    treeWidget->setFixedSize(300,400);
    dockWidget1->setWidget(treeWidget);

    dockWidget2 = new QDockWidget(tr("anniu"),this);
    dockWidget2->setFixedSize(300,500);
    AddButton = new QPushButton(tr("增加"));
    DeleteButton = new QPushButton(tr("删除"));

    dockWidget2->setWidget(AddButton);
    //dockWidget2->setWidget(DeleteButton);
    addDockWidget(Qt::LeftDockWidgetArea,dockWidget1);
    addDockWidget(Qt::RightDockWidgetArea,dockWidget2);
    connect(AddButton, SIGNAL(clicked(bool)),this,SLOT(addItems()));
    connect(DeleteButton, SIGNAL(clicked(bool)),this,SLOT(deleteItems()));
    connect(treeWidget,SIGNAL(itemPressed(QTreeWidgetItem *,int)),this,SLOT(SlotItemClicked(QTreeWidgetItem*,int)));
    createActionsParent();
    createActionsChild();
}

TreeItem::~TreeItem()
{
    delete ui;
}
void TreeItem::addItems()
{
    QTreeWidgetItem *item=new QTreeWidgetItem(treeWidget,QStringList(QString(tr("fileName"))));//添加节点
    //添加子节点
    QTreeWidgetItem *item1=new QTreeWidgetItem(item,QStringList(QString("Band1")));
    item->addChild(item1);
}
void TreeItem::deleteItems()
{

}
void TreeItem::createActionsParent()
{
    //创建菜单、菜单项
    pop_menu = new QMenu();
    add_images_action = new QAction(this);
    add_folder_action = new QAction(this);
    remove_selected_action = new QAction(this);
    remove_all_action = new QAction(this);

    //连接信号与槽
    connect(add_images_action, &QAction::triggered, this, &TreeItem::selectImages);
    connect(add_folder_action, &QAction::triggered, this, &TreeItem::selectFolder);
    connect(remove_selected_action, &QAction::triggered, this, &TreeItem::removeSelectedImages);
    connect(remove_all_action, &QAction::triggered, this, &TreeItem::removeAllImages);
}
void TreeItem::createActionsChild()
{
    //创建菜单、菜单项
    pop_menu = new QMenu();
    save_images_action = new QAction(this);
    save_folder_action = new QAction(this);
    save_selected_action = new QAction(this);
    save_all_action = new QAction(this);

    //连接信号与槽
    connect(save_images_action, &QAction::triggered, this, &TreeItem::selectImages);
    connect(save_folder_action, &QAction::triggered, this, &TreeItem::selectFolder);
    connect(save_selected_action, &QAction::triggered, this, &TreeItem::removeSelectedImages);
    connect(save_all_action, &QAction::triggered, this, &TreeItem::removeAllImages);
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
void TreeItem::selectImages(){
    qDebug()<<"selectImages";
    QTreeWidgetItem *item=new QTreeWidgetItem(treeWidget,QStringList(QString(tr("fileName"))));//添加节点
    //添加子节点
    QTreeWidgetItem *item1=new QTreeWidgetItem(item,QStringList(QString("Band1")));
    item->addChild(item1);
}
void TreeItem::selectFolder(){
    qDebug()<<"selectFolder";
}
void TreeItem::removeSelectedImages(){
    qDebug()<<"removeselected";
}
void TreeItem::removeAllImages(){
    qDebug()<<"removeall";
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
            pop_menu->addAction(add_images_action);
            pop_menu->addAction(add_folder_action);
            pop_menu->addAction(remove_selected_action);
            pop_menu->addAction(remove_all_action);
            add_images_action->setText(tr("添加组"));
            add_folder_action->setText(tr("修改组"));
            remove_selected_action->setText(tr("导入"));
            remove_all_action->setText(tr("删除组"));
            //菜单出现的位置为当前鼠标的位置
            pop_menu->exec(QCursor::pos());
            pop_menu->show();
            break;
        case 2:
            qDebug()<<"子节点";
            pop_menu->clear();
            pop_menu->addAction(save_images_action);
            pop_menu->addAction(save_folder_action);
            pop_menu->addAction(save_selected_action);
            pop_menu->addAction(save_all_action);
            save_images_action->setText(tr("保存参数"));
            save_folder_action->setText(tr("调用参数"));
            save_selected_action->setText(tr("修改参数"));
            save_all_action->setText(tr("删除节点"));
            //菜单出现的位置为当前鼠标的位置
            pop_menu->exec(QCursor::pos());
            pop_menu->show();
            break;
        }
    }
}
