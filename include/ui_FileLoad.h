/********************************************************************************
** Form generated from reading UI file 'FileLoad.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILELOAD_H
#define UI_FILELOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_FileLoad
{
public:
    QGridLayout *gridLayout;
    QTextEdit *luaViewer;
    QPushButton *loadScript;
    QPushButton *pushButton;

    void setupUi(QDialog *FileLoad)
    {
        if (FileLoad->objectName().isEmpty())
            FileLoad->setObjectName(QStringLiteral("FileLoad"));
        FileLoad->resize(817, 681);
        gridLayout = new QGridLayout(FileLoad);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        luaViewer = new QTextEdit(FileLoad);
        luaViewer->setObjectName(QStringLiteral("luaViewer"));

        gridLayout->addWidget(luaViewer, 0, 0, 1, 1);

        loadScript = new QPushButton(FileLoad);
        loadScript->setObjectName(QStringLiteral("loadScript"));

        gridLayout->addWidget(loadScript, 1, 0, 1, 1);

        pushButton = new QPushButton(FileLoad);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);


        retranslateUi(FileLoad);

        QMetaObject::connectSlotsByName(FileLoad);
    } // setupUi

    void retranslateUi(QDialog *FileLoad)
    {
        FileLoad->setWindowTitle(QApplication::translate("FileLoad", "Dialog", 0));
        loadScript->setText(QApplication::translate("FileLoad", "Load Lua Script from File", 0));
        pushButton->setText(QApplication::translate("FileLoad", "Save and Run", 0));
    } // retranslateUi

};

namespace Ui {
    class FileLoad: public Ui_FileLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILELOAD_H
