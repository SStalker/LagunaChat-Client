#include "state.h"
#include "MainWindow.h"

State::State()
{
}

void State::stateLogin(QObject *parent)
{
    MainWindow *main = (MainWindow*)parent;

    // Flip over to the chat page:
    main->stackedWidget->setCurrentWidget(main->chatPage);
    main->actionLogin->setText("Logout");
    main->connect(main->actionLogin,SIGNAL(triggered()),main,SLOT(logout_triggered()));

    main->sayLineEdit->setFocus();

    QString name;
    mainIn >> name;
    QSettings s;
    s.setValue("Username",name);
    //sende anfrage nach der userliste
    QDataStream out(this->sock);
    //QString regi(" + reg->getUsername() + ":" + reg->getPassword() + "\n");
    //int sizeOfText = regi.size();

    out << (int) 5;
    out << (int) 1;
    out << main->email;
    out << "\n";
}

void State::setDataStream(QDataStream in)
{
    this->mainIn = in;
}

void State::setSocket(QTcpSocket *s)
{
    this->sock = s;
}
