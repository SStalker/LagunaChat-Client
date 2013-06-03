/********************************************************************************
** Form generated from reading UI file 'chatwidget2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET2_H
#define UI_CHATWIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget2
{
public:
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;

    void setupUi(QWidget *ChatWidget2)
    {
        if (ChatWidget2->objectName().isEmpty())
            ChatWidget2->setObjectName(QStringLiteral("ChatWidget2"));
        ChatWidget2->resize(400, 300);
        ChatWidget2->setContextMenuPolicy(Qt::DefaultContextMenu);
        gridLayout_2 = new QGridLayout(ChatWidget2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget = new QTabWidget(ChatWidget2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(ChatWidget2);

        QMetaObject::connectSlotsByName(ChatWidget2);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget2)
    {
        ChatWidget2->setWindowTitle(QApplication::translate("ChatWidget2", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ChatWidget2", "Seite", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget2: public Ui_ChatWidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET2_H
