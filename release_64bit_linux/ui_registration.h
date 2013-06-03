/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_registration_email;
    QLineEdit *lineEdit_registration_email;
    QLabel *label_registration_username;
    QLineEdit *lineEdit_registration_username;
    QLabel *label_registration_password;
    QLineEdit *lineEdit_registration_password;
    QLineEdit *lineEdit_registration_password_2;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QStringLiteral("Registration"));
        Registration->setWindowModality(Qt::WindowModal);
        Registration->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        Registration->setWindowIcon(icon);
        Registration->setModal(true);
        gridLayout_3 = new QGridLayout(Registration);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label = new QLabel(Registration);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_registration_email = new QLabel(Registration);
        label_registration_email->setObjectName(QStringLiteral("label_registration_email"));
        label_registration_email->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_registration_email, 0, 0, 1, 1);

        lineEdit_registration_email = new QLineEdit(Registration);
        lineEdit_registration_email->setObjectName(QStringLiteral("lineEdit_registration_email"));
        lineEdit_registration_email->setMaxLength(50);

        gridLayout->addWidget(lineEdit_registration_email, 0, 1, 1, 1);

        label_registration_username = new QLabel(Registration);
        label_registration_username->setObjectName(QStringLiteral("label_registration_username"));
        label_registration_username->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_registration_username, 1, 0, 1, 1);

        lineEdit_registration_username = new QLineEdit(Registration);
        lineEdit_registration_username->setObjectName(QStringLiteral("lineEdit_registration_username"));
        lineEdit_registration_username->setMaxLength(32);

        gridLayout->addWidget(lineEdit_registration_username, 1, 1, 1, 1);

        label_registration_password = new QLabel(Registration);
        label_registration_password->setObjectName(QStringLiteral("label_registration_password"));
        label_registration_password->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_registration_password, 2, 0, 1, 1);

        lineEdit_registration_password = new QLineEdit(Registration);
        lineEdit_registration_password->setObjectName(QStringLiteral("lineEdit_registration_password"));
        lineEdit_registration_password->setMaxLength(32);
        lineEdit_registration_password->setEchoMode(QLineEdit::Password);
        lineEdit_registration_password->setReadOnly(false);

        gridLayout->addWidget(lineEdit_registration_password, 2, 1, 1, 1);

        lineEdit_registration_password_2 = new QLineEdit(Registration);
        lineEdit_registration_password_2->setObjectName(QStringLiteral("lineEdit_registration_password_2"));
        lineEdit_registration_password_2->setMaxLength(32);
        lineEdit_registration_password_2->setEchoMode(QLineEdit::Password);
        lineEdit_registration_password_2->setReadOnly(false);

        gridLayout->addWidget(lineEdit_registration_password_2, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Registration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(Registration);
        QObject::connect(buttonBox, SIGNAL(accepted()), Registration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Registration, SLOT(reject()));

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QDialog *Registration)
    {
        Registration->setWindowTitle(QApplication::translate("Registration", "Registration", 0));
        label->setText(QApplication::translate("Registration", "Registration", 0));
        label_registration_email->setText(QApplication::translate("Registration", "E-Mail:", 0));
        lineEdit_registration_email->setPlaceholderText(QApplication::translate("Registration", "Your E-Mailaddress", 0));
        label_registration_username->setText(QApplication::translate("Registration", "Username:", 0));
        lineEdit_registration_username->setPlaceholderText(QApplication::translate("Registration", "Your Username", 0));
        label_registration_password->setText(QApplication::translate("Registration", "Password:", 0));
        lineEdit_registration_password->setPlaceholderText(QApplication::translate("Registration", "Your Password", 0));
        lineEdit_registration_password_2->setText(QString());
        lineEdit_registration_password_2->setPlaceholderText(QApplication::translate("Registration", "Password again", 0));
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
