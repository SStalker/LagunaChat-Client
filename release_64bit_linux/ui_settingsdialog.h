/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelServerAddress;
    QLineEdit *lineEditServerAddress;
    QLabel *labelServerPort;
    QComboBox *comboBoxServerPort;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->setWindowModality(Qt::ApplicationModal);
        SettingsDialog->resize(490, 355);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        SettingsDialog->setModal(true);
        gridLayout_2 = new QGridLayout(SettingsDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelServerAddress = new QLabel(SettingsDialog);
        labelServerAddress->setObjectName(QStringLiteral("labelServerAddress"));
        labelServerAddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelServerAddress, 0, 0, 1, 1);

        lineEditServerAddress = new QLineEdit(SettingsDialog);
        lineEditServerAddress->setObjectName(QStringLiteral("lineEditServerAddress"));

        gridLayout->addWidget(lineEditServerAddress, 0, 1, 1, 1);

        labelServerPort = new QLabel(SettingsDialog);
        labelServerPort->setObjectName(QStringLiteral("labelServerPort"));
        labelServerPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelServerPort, 1, 0, 1, 1);

        comboBoxServerPort = new QComboBox(SettingsDialog);
        comboBoxServerPort->setObjectName(QStringLiteral("comboBoxServerPort"));

        gridLayout->addWidget(comboBoxServerPort, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", 0));
        labelServerAddress->setText(QApplication::translate("SettingsDialog", "Server:", 0));
        labelServerPort->setText(QApplication::translate("SettingsDialog", "Port:", 0));
        comboBoxServerPort->clear();
        comboBoxServerPort->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "4402", 0)
         << QApplication::translate("SettingsDialog", "4444", 0)
         << QApplication::translate("SettingsDialog", "4201", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
