/********************************************************************************
** Form generated from reading UI file 'dialogadduser.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDUSER_H
#define UI_DIALOGADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAddUser
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAddUser)
    {
        if (DialogAddUser->objectName().isEmpty())
            DialogAddUser->setObjectName(QStringLiteral("DialogAddUser"));
        DialogAddUser->setWindowModality(Qt::ApplicationModal);
        DialogAddUser->resize(262, 82);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogAddUser->setWindowIcon(icon);
        DialogAddUser->setModal(true);
        gridLayout_2 = new QGridLayout(DialogAddUser);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        labelEmail = new QLabel(DialogAddUser);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(DialogAddUser);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setMaxLength(50);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditEmail);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogAddUser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(DialogAddUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddUser, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddUser);
    } // setupUi

    void retranslateUi(QDialog *DialogAddUser)
    {
        DialogAddUser->setWindowTitle(QApplication::translate("DialogAddUser", "Add User", 0));
        labelEmail->setText(QApplication::translate("DialogAddUser", "Email:", 0));
        lineEditEmail->setPlaceholderText(QApplication::translate("DialogAddUser", "Email", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogAddUser: public Ui_DialogAddUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDUSER_H
