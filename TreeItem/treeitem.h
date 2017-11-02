#ifndef TREEITEM_H
#define TREEITEM_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QDockWidget>
#include <QPushButton>
#include <QAction>
#include <QContextMenuEvent>
#include <QMenu>
#include <QPoint>
#include <QDebug>
#include "adddialog.h"
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QWidget>
#include <QVector>

class QAction;
namespace Ui {
class TreeItem;
}

class TreeItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit TreeItem(QWidget *parent = 0);
    ~TreeItem();
    QString receiveData;
//void TreeItem::AddItem();
private slots:
void addParentNode();
void addChildNode(QTreeWidgetItem *item);
void deleteItems();

void addGroup();
void changeGroup();
void load();
void deleteGroup();

void changePara();
void savePara();
void usePara();
void deleteMach();

void SlotItemClicked(QTreeWidgetItem *item, int column);
void contextMenuEvent ( QContextMenuEvent * event );
void mouseReleaseEvent(QMouseEvent * event);
void receiceData(QString data);

//QVector<QTreeWidgetItem*> Nodes;
//QVector<QString> strArray;

private:
    Ui::TreeItem *ui;
    QTreeWidget *treeWidget;
    QDockWidget *dockWidget1;
    QDockWidget *dockWidget2;
    QDockWidget *dockWidget3;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QMenu *pop_menu;
    QAction *addGroupAction;
    QAction *changeGroupAction;
    QAction *loadAction;
    QAction *deleteGroupAction;
    QAction *saveParaAction;
    QAction *useParaAction;
    QAction *changeParaAction;
    QAction *deleteMachAction;
    QListWidget *msgList;
    QLineEdit *edit;
    QTreeWidgetItem *initItem;
    QTreeWidgetItem *pCurrentItem;

    void createActionsParent();
    void createActionsChild();
 //   void contextMenuEvent(QContextMenuEvent *event);
};

#endif // TREEITEM_H
