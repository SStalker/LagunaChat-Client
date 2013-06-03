/********************************************************************************
** Form generated from reading UI file 'newuserauthdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERAUTHDIALOG_H
#define UI_NEWUSERAUTHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_newUserAuthDialog
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *labelUsername;
    QLabel *label_3;
    QLabel *labelEmail;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newUserAuthDialog)
    {
        if (newUserAuthDialog->objectName().isEmpty())
            newUserAuthDialog->setObjectName(QStringLiteral("newUserAuthDialog"));
        newUserAuthDialog->setWindowModality(Qt::ApplicationModal);
        newUserAuthDialog->resize(400, 162);
        gridLayout_3 = new QGridLayout(newUserAuthDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(newUserAuthDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(newUserAuthDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        labelUsername = new QLabel(newUserAuthDialog);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));
        labelUsername->setMinimumSize(QSize(250, 14));

        gridLayout->addWidget(labelUsername, 0, 1, 1, 1);

        label_3 = new QLabel(newUserAuthDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        labelEmail = new QLabel(newUserAuthDialog);
        labelEmail->setObjectName(QStringLiteral("labelEmail"));
        labelEmail->setMinimumSize(QSize(250, 14));

        gridLayout->addWidget(labelEmail, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        label_4 = new QLabel(newUserAuthDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setPointSize(12);
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(newUserAuthDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 4, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(newUserAuthDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newUserAuthDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newUserAuthDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newUserAuthDialog);
    } // setupUi

    void retranslateUi(QDialog *newUserAuthDialog)
    {
        newUserAuthDialog->setWindowTitle(QApplication::translate("newUserAuthDialog", "Dialog", 0));
        label->setText(QApplication::translate("newUserAuthDialog", "Ein neuer User m\303\266chte gern dein Freund sein", 0));
        label_2->setText(QApplication::translate("newUserAuthDialog", "Username:", 0));
        labelUsername->setText(QString());
        label_3->setText(QApplication::translate("newUserAuthDialog", "Email:", 0));
        labelEmail->setText(QString());
        label_4->setText(QApplication::translate("newUserAuthDialog", "M\303\266chtest du den User authorisieren?", 0));
    } // retranslateUi

};

namespace Ui {
    class newUserAuthDialog: public Ui_newUserAuthDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERAUTHDIALOG_H
