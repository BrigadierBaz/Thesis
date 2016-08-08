/********************************************************************************
** Form generated from reading UI file 'UserInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInterface
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainWindowGridLayout;
    QPushButton *pushButton_2;
    QPushButton *restartSim;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QDoubleSpinBox *neighborDistance;
    QLabel *label_3;
    QLabel *label_2;
    QDoubleSpinBox *agentRadius;
    QSpinBox *numNeighbors;
    QLabel *label;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserInterface)
    {
        if (UserInterface->objectName().isEmpty())
            UserInterface->setObjectName(QStringLiteral("UserInterface"));
        UserInterface->resize(1600, 900);
        centralwidget = new QWidget(UserInterface);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        s_mainWindowGridLayout = new QGridLayout(centralwidget);
        s_mainWindowGridLayout->setObjectName(QStringLiteral("s_mainWindowGridLayout"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        s_mainWindowGridLayout->addWidget(pushButton_2, 2, 2, 1, 1);

        restartSim = new QPushButton(centralwidget);
        restartSim->setObjectName(QStringLiteral("restartSim"));

        s_mainWindowGridLayout->addWidget(restartSim, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        s_mainWindowGridLayout->addItem(verticalSpacer, 4, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        neighborDistance = new QDoubleSpinBox(centralwidget);
        neighborDistance->setObjectName(QStringLiteral("neighborDistance"));
        neighborDistance->setMinimum(0.1);
        neighborDistance->setMaximum(100);
        neighborDistance->setSingleStep(0.1);
        neighborDistance->setValue(15);

        gridLayout->addWidget(neighborDistance, 2, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        agentRadius = new QDoubleSpinBox(centralwidget);
        agentRadius->setObjectName(QStringLiteral("agentRadius"));
        agentRadius->setMinimum(0.1);
        agentRadius->setMaximum(5);
        agentRadius->setSingleStep(0.1);
        agentRadius->setValue(2);

        gridLayout->addWidget(agentRadius, 0, 1, 1, 1);

        numNeighbors = new QSpinBox(centralwidget);
        numNeighbors->setObjectName(QStringLiteral("numNeighbors"));
        numNeighbors->setMinimum(1);
        numNeighbors->setMaximum(50);
        numNeighbors->setValue(15);

        gridLayout->addWidget(numNeighbors, 1, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        s_mainWindowGridLayout->addLayout(gridLayout, 0, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        s_mainWindowGridLayout->addWidget(pushButton, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainWindowGridLayout->addItem(horizontalSpacer, 0, 0, 5, 1);

        UserInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserInterface);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1600, 27));
        UserInterface->setMenuBar(menubar);
        toolBar = new QToolBar(UserInterface);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        UserInterface->addToolBar(Qt::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(UserInterface);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        UserInterface->setStatusBar(statusbar);

        retranslateUi(UserInterface);

        QMetaObject::connectSlotsByName(UserInterface);
    } // setupUi

    void retranslateUi(QMainWindow *UserInterface)
    {
        UserInterface->setWindowTitle(QApplication::translate("UserInterface", "Luke Bazalgette Thesis 2016", 0));
        pushButton_2->setText(QApplication::translate("UserInterface", "Save and Run script", 0));
        restartSim->setText(QApplication::translate("UserInterface", "Restart Simulation", 0));
        label_3->setText(QApplication::translate("UserInterface", "Neighbor Distance", 0));
        label_2->setText(QApplication::translate("UserInterface", "Number of Neighbors", 0));
        label->setText(QApplication::translate("UserInterface", "Agent Radius", 0));
        pushButton->setText(QApplication::translate("UserInterface", "Load LUA Script from file", 0));
        toolBar->setWindowTitle(QApplication::translate("UserInterface", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class UserInterface: public Ui_UserInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
