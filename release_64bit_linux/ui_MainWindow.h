/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRegistration;
    QAction *actionQuit;
    QAction *actionSettings;
    QAction *actionConnect;
    QAction *actionLogin;
    QAction *actionAdd_User;
    QAction *actionDelete_User;
    QAction *actionCreate_Room;
    QAction *actionDelete_Room;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QFrame *mainFrame;
    QStackedWidget *stackedWidget;
    QWidget *chatPage;
    QGridLayout *gridLayout;
    QTextEdit *roomTextEdit;
    QLineEdit *sayLineEdit;
    QPushButton *sayButton;
    QListWidget *userListWidget;
    QLabel *titleLabel;
    QLabel *charLabel;
    QWidget *loginPage;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QFrame *loginFrame;
    QGridLayout *gridLayout_2;
    QLabel *labelUsername;
    QLineEdit *LineEditEmail;
    QLabel *labelPassword;
    QLineEdit *LineEditPassword;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuProgram;
    QMenu *menuExtras;
    QMenu *menuUser;
    QStatusBar *statusBarMain;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QLatin1String("#titleLabel {\n"
"background: white;\n"
"color: blue;\n"
"font-size: 20px;\n"
"border: none;\n"
"border-bottom:  1px solid black;\n"
"padding: 5px;\n"
"}\n"
"\n"
"#mainFrame {\n"
"border: none;\n"
"background: white;\n"
"}\n"
"\n"
"#loginFrame {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ddf, stop: 1 #aaf);\n"
"border: 1px solid gray;\n"
"padding: 10px;\n"
"border-radius: 25px;\n"
"}"));
        actionRegistration = new QAction(MainWindow);
        actionRegistration->setObjectName(QStringLiteral("actionRegistration"));
        actionRegistration->setEnabled(false);
        actionRegistration->setVisible(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionLogin = new QAction(MainWindow);
        actionLogin->setObjectName(QStringLiteral("actionLogin"));
        actionLogin->setEnabled(false);
        actionLogin->setVisible(false);
        actionAdd_User = new QAction(MainWindow);
        actionAdd_User->setObjectName(QStringLiteral("actionAdd_User"));
        actionAdd_User->setEnabled(false);
        actionAdd_User->setVisible(false);
        actionDelete_User = new QAction(MainWindow);
        actionDelete_User->setObjectName(QStringLiteral("actionDelete_User"));
        actionDelete_User->setEnabled(false);
        actionDelete_User->setVisible(false);
        actionCreate_Room = new QAction(MainWindow);
        actionCreate_Room->setObjectName(QStringLiteral("actionCreate_Room"));
        actionCreate_Room->setEnabled(false);
        actionCreate_Room->setVisible(false);
        actionDelete_Room = new QAction(MainWindow);
        actionDelete_Room->setObjectName(QStringLiteral("actionDelete_Room"));
        actionDelete_Room->setEnabled(false);
        actionDelete_Room->setVisible(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName(QStringLiteral("mainFrame"));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        stackedWidget = new QStackedWidget(mainFrame);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(32, 29, 721, 501));
        stackedWidget->setLineWidth(1);
        chatPage = new QWidget();
        chatPage->setObjectName(QStringLiteral("chatPage"));
        gridLayout = new QGridLayout(chatPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        roomTextEdit = new QTextEdit(chatPage);
        roomTextEdit->setObjectName(QStringLiteral("roomTextEdit"));
        roomTextEdit->setReadOnly(true);
        roomTextEdit->setTextInteractionFlags(Qt::TextBrowserInteraction);

        gridLayout->addWidget(roomTextEdit, 1, 0, 1, 1);

        sayLineEdit = new QLineEdit(chatPage);
        sayLineEdit->setObjectName(QStringLiteral("sayLineEdit"));
        sayLineEdit->setEnabled(false);
        sayLineEdit->setMaxLength(255);

        gridLayout->addWidget(sayLineEdit, 2, 0, 1, 1);

        sayButton = new QPushButton(chatPage);
        sayButton->setObjectName(QStringLiteral("sayButton"));
        sayButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sayButton->sizePolicy().hasHeightForWidth());
        sayButton->setSizePolicy(sizePolicy);
        sayButton->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(sayButton, 2, 2, 1, 1);

        userListWidget = new QListWidget(chatPage);
        userListWidget->setObjectName(QStringLiteral("userListWidget"));

        gridLayout->addWidget(userListWidget, 1, 1, 1, 2);

        titleLabel = new QLabel(chatPage);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(titleLabel, 0, 0, 1, 3);

        charLabel = new QLabel(chatPage);
        charLabel->setObjectName(QStringLiteral("charLabel"));

        gridLayout->addWidget(charLabel, 2, 1, 1, 1);

        stackedWidget->addWidget(chatPage);
        loginPage = new QWidget();
        loginPage->setObjectName(QStringLiteral("loginPage"));
        gridLayout_3 = new QGridLayout(loginPage);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        loginFrame = new QFrame(loginPage);
        loginFrame->setObjectName(QStringLiteral("loginFrame"));
        sizePolicy.setHeightForWidth(loginFrame->sizePolicy().hasHeightForWidth());
        loginFrame->setSizePolicy(sizePolicy);
        loginFrame->setMinimumSize(QSize(300, 0));
        loginFrame->setFrameShape(QFrame::StyledPanel);
        gridLayout_2 = new QGridLayout(loginFrame);
        gridLayout_2->setSpacing(20);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelUsername = new QLabel(loginFrame);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));

        gridLayout_2->addWidget(labelUsername, 0, 0, 1, 1);

        LineEditEmail = new QLineEdit(loginFrame);
        LineEditEmail->setObjectName(QStringLiteral("LineEditEmail"));
        LineEditEmail->setMaxLength(50);

        gridLayout_2->addWidget(LineEditEmail, 0, 1, 1, 1);

        labelPassword = new QLabel(loginFrame);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        gridLayout_2->addWidget(labelPassword, 1, 0, 1, 1);

        LineEditPassword = new QLineEdit(loginFrame);
        LineEditPassword->setObjectName(QStringLiteral("LineEditPassword"));
        LineEditPassword->setMaxLength(32);
        LineEditPassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(LineEditPassword, 1, 1, 1, 1);

        loginButton = new QPushButton(loginFrame);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setEnabled(false);
        sizePolicy.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(loginButton, 2, 1, 1, 1);


        gridLayout_3->addWidget(loginFrame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 267, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 1, 1, 1);

        stackedWidget->addWidget(loginPage);

        gridLayout_4->addWidget(mainFrame, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuProgram = new QMenu(menuBar);
        menuProgram->setObjectName(QStringLiteral("menuProgram"));
        menuExtras = new QMenu(menuBar);
        menuExtras->setObjectName(QStringLiteral("menuExtras"));
        menuUser = new QMenu(menuBar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        MainWindow->setMenuBar(menuBar);
        statusBarMain = new QStatusBar(MainWindow);
        statusBarMain->setObjectName(QStringLiteral("statusBarMain"));
        MainWindow->setStatusBar(statusBarMain);
        QWidget::setTabOrder(LineEditEmail, LineEditPassword);
        QWidget::setTabOrder(LineEditPassword, loginButton);

        menuBar->addAction(menuProgram->menuAction());
        menuBar->addAction(menuUser->menuAction());
        menuBar->addAction(menuExtras->menuAction());
        menuProgram->addAction(actionLogin);
        menuProgram->addAction(actionRegistration);
        menuProgram->addAction(actionConnect);
        menuProgram->addSeparator();
        menuProgram->addAction(actionQuit);
        menuExtras->addAction(actionSettings);
        menuUser->addAction(actionAdd_User);
        menuUser->addAction(actionDelete_User);
        menuUser->addSeparator();
        menuUser->addAction(actionCreate_Room);
        menuUser->addAction(actionDelete_Room);

        retranslateUi(MainWindow);
        QObject::connect(sayLineEdit, SIGNAL(returnPressed()), sayButton, SLOT(animateClick()));
        QObject::connect(LineEditEmail, SIGNAL(returnPressed()), LineEditPassword, SLOT(setFocus()));
        QObject::connect(LineEditPassword, SIGNAL(returnPressed()), loginButton, SLOT(animateClick()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Laguna Chat", 0));
        actionRegistration->setText(QApplication::translate("MainWindow", "Registration", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionLogin->setText(QApplication::translate("MainWindow", "Login", 0));
        actionAdd_User->setText(QApplication::translate("MainWindow", "Add User", 0));
        actionDelete_User->setText(QApplication::translate("MainWindow", "Delete User", 0));
        actionCreate_Room->setText(QApplication::translate("MainWindow", "Create Room", 0));
        actionDelete_Room->setText(QApplication::translate("MainWindow", "Delete Room", 0));
        sayButton->setText(QApplication::translate("MainWindow", "Say", 0));
        titleLabel->setText(QApplication::translate("MainWindow", "Chatclient by Raphael Grewe", 0));
        charLabel->setText(QString());
        labelUsername->setText(QApplication::translate("MainWindow", "Email:", 0));
        LineEditEmail->setText(QString());
        LineEditEmail->setPlaceholderText(QApplication::translate("MainWindow", "Address", 0));
        labelPassword->setText(QApplication::translate("MainWindow", "Password:", 0));
        LineEditPassword->setText(QString());
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0));
        menuProgram->setTitle(QApplication::translate("MainWindow", "Program", 0));
        menuExtras->setTitle(QApplication::translate("MainWindow", "Extras", 0));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
