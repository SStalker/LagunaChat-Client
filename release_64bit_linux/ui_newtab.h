/********************************************************************************
** Form generated from reading UI file 'newtab.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTAB_H
#define UI_NEWTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newTab
{
public:
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;

    void setupUi(QWidget *newTab)
    {
        if (newTab->objectName().isEmpty())
            newTab->setObjectName(QStringLiteral("newTab"));
        newTab->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        newTab->setWindowIcon(icon);
        gridLayout = new QGridLayout(newTab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(newTab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        lineEdit = new QLineEdit(newTab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);


        retranslateUi(newTab);

        QMetaObject::connectSlotsByName(newTab);
    } // setupUi

    void retranslateUi(QWidget *newTab)
    {
        newTab->setWindowTitle(QApplication::translate("newTab", "Chats", 0));
    } // retranslateUi

};

namespace Ui {
    class newTab: public Ui_newTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTAB_H
