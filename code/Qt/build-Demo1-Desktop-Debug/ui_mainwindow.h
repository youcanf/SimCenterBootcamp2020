/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *folderButton;
    QLabel *folder_label;
    QLineEdit *folderName;
    QLabel *filename_label;
    QLineEdit *filename;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        folderButton = new QPushButton(centralwidget);
        folderButton->setObjectName(QStringLiteral("folderButton"));

        gridLayout->addWidget(folderButton, 1, 2, 1, 1);

        folder_label = new QLabel(centralwidget);
        folder_label->setObjectName(QStringLiteral("folder_label"));

        gridLayout->addWidget(folder_label, 1, 0, 1, 1);

        folderName = new QLineEdit(centralwidget);
        folderName->setObjectName(QStringLiteral("folderName"));

        gridLayout->addWidget(folderName, 1, 1, 1, 1);

        filename_label = new QLabel(centralwidget);
        filename_label->setObjectName(QStringLiteral("filename_label"));

        gridLayout->addWidget(filename_label, 0, 0, 1, 1);

        filename = new QLineEdit(centralwidget);
        filename->setObjectName(QStringLiteral("filename"));

        gridLayout->addWidget(filename, 0, 1, 1, 2);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        folderButton->setText(QApplication::translate("MainWindow", "locate", Q_NULLPTR));
        folder_label->setText(QApplication::translate("MainWindow", "Folder", Q_NULLPTR));
        filename_label->setText(QApplication::translate("MainWindow", "Filename", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
