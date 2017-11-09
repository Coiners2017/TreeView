/********************************************************************************
** Form generated from reading UI file 'lightftpclientdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTFTPCLIENTDLG_H
#define UI_LIGHTFTPCLIENTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LightFtpClientDlg
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LightFtpClientDlg)
    {
        if (LightFtpClientDlg->objectName().isEmpty())
            LightFtpClientDlg->setObjectName(QStringLiteral("LightFtpClientDlg"));
        LightFtpClientDlg->resize(400, 300);
        menuBar = new QMenuBar(LightFtpClientDlg);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        LightFtpClientDlg->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LightFtpClientDlg);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LightFtpClientDlg->addToolBar(mainToolBar);
        centralWidget = new QWidget(LightFtpClientDlg);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LightFtpClientDlg->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LightFtpClientDlg);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LightFtpClientDlg->setStatusBar(statusBar);

        retranslateUi(LightFtpClientDlg);

        QMetaObject::connectSlotsByName(LightFtpClientDlg);
    } // setupUi

    void retranslateUi(QMainWindow *LightFtpClientDlg)
    {
        LightFtpClientDlg->setWindowTitle(QApplication::translate("LightFtpClientDlg", "LightFtpClientDlg", 0));
    } // retranslateUi

};

namespace Ui {
    class LightFtpClientDlg: public Ui_LightFtpClientDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTFTPCLIENTDLG_H
