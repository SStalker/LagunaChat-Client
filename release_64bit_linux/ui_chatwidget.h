/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:

    void setupUi(QTabWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName(QStringLiteral("ChatWidget"));
        ChatWidget->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        ChatWidget->setWindowIcon(icon);
        ChatWidget->setTabPosition(QTabWidget::North);
        ChatWidget->setUsesScrollButtons(true);
        ChatWidget->setDocumentMode(false);
        ChatWidget->setTabsClosable(true);
        ChatWidget->setMovable(true);

        retranslateUi(ChatWidget);

        ChatWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QTabWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QApplication::translate("ChatWidget", "LagunaChats", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
