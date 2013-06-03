/********************************************************************************
** Form generated from reading UI file 'dialogdeletefriendship.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDELETEFRIENDSHIP_H
#define UI_DIALOGDELETEFRIENDSHIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogDeleteFriendship
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogDeleteFriendship)
    {
        if (DialogDeleteFriendship->objectName().isEmpty())
            DialogDeleteFriendship->setObjectName(QStringLiteral("DialogDeleteFriendship"));
        DialogDeleteFriendship->setWindowModality(Qt::ApplicationModal);
        DialogDeleteFriendship->resize(262, 86);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogDeleteFriendship->setWindowIcon(icon);
        DialogDeleteFriendship->setModal(true);
        gridLayout_3 = new QGridLayout(DialogDeleteFriendship);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelEmail = new QLabel(DialogDeleteFriendship);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));

        gridLayout->addWidget(labelEmail, 0, 0, 1, 1);

        lineEditEmail = new QLineEdit(DialogDeleteFriendship);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));
        lineEditEmail->setMaxLength(50);

        gridLayout->addWidget(lineEditEmail, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(DialogDeleteFriendship);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(DialogDeleteFriendship);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogDeleteFriendship, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogDeleteFriendship, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogDeleteFriendship);
    } // setupUi

    void retranslateUi(QDialog *DialogDeleteFriendship)
    {
        DialogDeleteFriendship->setWindowTitle(QApplication::translate("DialogDeleteFriendship", "Delete Friendship", 0));
        labelEmail->setText(QApplication::translate("DialogDeleteFriendship", "Email:", 0));
        lineEditEmail->setPlaceholderText(QApplication::translate("DialogDeleteFriendship", "Email", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogDeleteFriendship: public Ui_DialogDeleteFriendship {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDELETEFRIENDSHIP_H
