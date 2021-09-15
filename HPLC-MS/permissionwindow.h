#ifndef PERMISSIONWINDOW_H
#define PERMISSIONWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QVBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <QStandardItemModel>
#include <QStyleFactory>
#include <QDebug>
#include <QMap>
#include <QFile>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
namespace Ui {
class PermissionWindow;
}

class PermissionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PermissionWindow(QWidget *parent = nullptr);
    ~PermissionWindow();


public:
      QToolButton *toolButton;
public slots:
      void saveTreeItemSelected();
      void getItemChanged(QStandardItem *item);
      void treeItemChanged(QStandardItem *item);
      void OnlineTreeViewDoubleClick(const QModelIndex);
private:
    Ui::PermissionWindow *ui;
    QTreeView *treeView;
    QToolBar *toolBar;
    QList<QString> list;

};

#endif // PERMISSIONWINDOW_H
