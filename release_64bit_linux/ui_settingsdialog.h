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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QGridLayout *gridLayout_2;
    QDialogButtonBox *buttonBox;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout;
    QLabel *labelServerAddress;
    QLineEdit *lineEditServerAddress;
    QLabel *labelServerPort;
    QComboBox *comboBoxServerPort;
    QSpacerItem *verticalSpacer;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QWidget *page_3;
    QCheckBox *checkBox;
    QWidget *page_4;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->setWindowModality(Qt::ApplicationModal);
        SettingsDialog->resize(488, 418);
        QIcon icon;
        icon.addFile(QStringLiteral(":/internet-chat-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        SettingsDialog->setModal(true);
        gridLayout_2 = new QGridLayout(SettingsDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);

        toolBox = new QToolBox(SettingsDialog);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 470, 260));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelServerAddress = new QLabel(page);
        labelServerAddress->setObjectName(QStringLiteral("labelServerAddress"));
        labelServerAddress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelServerAddress, 0, 0, 1, 1);

        lineEditServerAddress = new QLineEdit(page);
        lineEditServerAddress->setObjectName(QStringLiteral("lineEditServerAddress"));

        gridLayout->addWidget(lineEditServerAddress, 0, 1, 1, 1);

        labelServerPort = new QLabel(page);
        labelServerPort->setObjectName(QStringLiteral("labelServerPort"));
        labelServerPort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelServerPort, 1, 0, 1, 1);

        comboBoxServerPort = new QComboBox(page);
        comboBoxServerPort->setObjectName(QStringLiteral("comboBoxServerPort"));

        gridLayout->addWidget(comboBoxServerPort, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        toolBox->addItem(page, QStringLiteral("Netzwerk"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 470, 260));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 211, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 0, 1, 1);

        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Schrift"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        checkBox = new QCheckBox(page_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(12, 12, 151, 20));
        toolBox->addItem(page_3, QStringLiteral("Logging"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setEnabled(false);
        toolBox->addItem(page_4, QStringLiteral("Sounds"));

        gridLayout_2->addWidget(toolBox, 0, 0, 1, 1);


        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        toolBox->setCurrentIndex(3);


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
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("SettingsDialog", "Netzwerk", 0));
        pushButton->setText(QApplication::translate("SettingsDialog", "Schriftart \303\244ndern", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("SettingsDialog", "Schrift", 0));
        checkBox->setText(QApplication::translate("SettingsDialog", "Logging aktivieren?", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("SettingsDialog", "Logging", 0));
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("SettingsDialog", "Sounds", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
