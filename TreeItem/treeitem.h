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
//void TreeItem::AddItem();
private slots:
void addItems();
void deleteItems();
void selectImages();
void selectFolder();
void removeSelectedImages();
void removeAllImages();
void SlotItemClicked(QTreeWidgetItem *item, int column);
private:
    Ui::TreeItem *ui;
    QTreeWidget *treeWidget;
    QDockWidget *dockWidget1;
    QDockWidget *dockWidget2;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QMenu *pop_menu;
    QAction *add_images_action;
    QAction *add_folder_action;
    QAction *remove_selected_action;
    QAction *remove_all_action;
    QAction *save_images_action;
    QAction *save_folder_action;
    QAction *save_selected_action;
    QAction *save_all_action;
    void createActionsParent();
    void createActionsChild();
 //   void contextMenuEvent(QContextMenuEvent *event);
};

#endif // TREEITEM_H
