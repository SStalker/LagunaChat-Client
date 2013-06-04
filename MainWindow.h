// We need to include a couple Qt classes that we'll use:
#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QSettings>

// This is the include file that Qt generates for us from the
// GUI we built in Designer  
#include "ui_MainWindow.h"
#include "chatwidget.h"

/*
 * This is the MainWindow class that we have told to inherit from
 * our Designer MainWindow (ui::MainWindow)
 */
class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

    public:

        // Every QWidget needs a constructor, and they should allow
        // the user to pass a parent QWidget (or not).
        MainWindow(QWidget *parent=0);
        QSettings *settings;

        ChatWidget *cw;

        bool checkUserInList(QString user);
        QListWidgetItem* getUserInList(QString user);

    private slots:

        // This function gets called when a user clicks on the
        // loginButton on the front page (which you placed there
        // with Designer)
        void on_loginButton_clicked();

        // This gets called when you click the sayButton on
        // the chat page.
        void on_sayButton_clicked();

        // This is a function we'll connect to a socket's readyRead()
        // signal, which tells us there's text to be read from the chat
        // server.
        void readyRead();

        // This function gets called when the socket tells us it's connected.
        void connected();

        //This function get called when a user rightclick on one of the users from the userlist
        void wasDoubleClicked(QListWidgetItem *user);

        //Data send to user
        void data_send();

        //Count the typping chars
        void setCountValue(QString);
        void socketError(QAbstractSocket::SocketError error);
        void on_actionRegistration_triggered();

        void changeRegistrationMode();

        void on_actionSettings_triggered();

        void on_actionConnect_triggered();

        void on_actionLogin_triggered();

        void on_actionQuit_triggered();

        void logout_triggered();

        void on_actionAdd_User_triggered();

        void on_actionDelete_User_triggered();

        void on_actionCreate_Room_triggered();

        void on_actionDelete_Room_triggered();

        void on_actionSend_Data_triggered();

signals:
        // Count the typping chars
        void countValueChar(QString);
    private:

        // This is the socket that will let us communitate with the server.
        QTcpSocket *socket;

        QDataStream in;
        QDataStream out;
        QTimer *registrationTimer;
        int waitToRegistration;
        bool RegistrationMode;
        QHostAddress ipv4;
        QString email;

        QString toMD5(QString text);
};
