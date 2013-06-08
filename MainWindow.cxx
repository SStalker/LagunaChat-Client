#include "MainWindow.h"
#include "dialog.h"
#include "registration.h"
#include "protocol.h"
#include "settingsdialog.h"
#include "dialogadduser.h"
#include "newuserauthdialog.h"
#include "newdataauthdialog.h"
#include "dialogdeletefriendship.h"
#include "chatwidget.h"
#include "newtab.h"
#include "filetransfersender.h"

// Own classes to minify my sourcecode and make it more readable
#include "error.h"

#include <QRegExp>
#include <QMessageBox>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QKeyEvent>
#include <QFileDialog>
#include <QTimer>
#include <QDataStream>
#include <QCryptographicHash>
#include <QHostAddress>
#include <QSettings>

#include <QMultiMap>



// This is our MainWindow constructor (you C++ n00b)
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // When using Designer, you should always call setupUi(this)
    // in your constructor. This creates and lays out all the widgets
    // on the MainWindow that you setup in Designer.
    setupUi(this);

    // load icon
       QIcon icon = QIcon(":/linux2.png");

        // build menu
        QMenu *trayMenu = new QMenu(this);
        QAction *action1 = new QAction("Datei senden an",this);
        QAction *action2 = new QAction("Beenden",this);

        connect(action1, SIGNAL(triggered()), this, SLOT(data_send()) );
        connect(action2, SIGNAL(triggered()), this, SLOT(close()) );

        trayMenu->addAction(action1);
        trayMenu->addAction(action2);

        // set up and show the system tray icon
        /*QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(icon);
        trayIcon->setContextMenu(trayMenu);
        trayIcon->show();
        */

    // Make sure that we are showing the login page when we startup:
    stackedWidget->setCurrentWidget(loginPage);

    // Instantiate our socket (but don't actually connect to anything
    // yet until the user clicks the loginButton:
    socket = new QTcpSocket(this);

    registrationTimer = new QTimer(this);
    waitToRegistration = 120000;
    RegistrationMode = true;
    // This is how we tell Qt to call our readyRead() and connected()
    // functions when the socket has text ready to be read, and is done
    // connecting to the server (respectively):
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketError(QAbstractSocket::SocketError)));
    connect(sayLineEdit,SIGNAL(textChanged(QString)),this,SLOT(setCountValue(QString)));

    connect(userListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(wasDoubleClicked(QListWidgetItem*)));

    QSettings s;
    LineEditEmail->setText(s.value("UserEmail").toString());
    //socket->connectToHost(s.value("ServerAddress").toString(),s.value("ServerPort").toInt());
    //socket->connectToHost("localhost", 4201);

    cw = new ChatWidget();

    in.setDevice(socket);
    out.setDevice(socket);

    error = new Error();
    //state = new State();
}

// This gets called when the loginButton gets clicked:
// We didn't have to use connect() to set this up because
// Qt recognizes the name of this function and knows to set
// up the signal/slot connection for us.
void MainWindow::on_loginButton_clicked()
{
    qDebug() << "LoginBUtton wurde geklickt";
    QDataStream out(socket);

    out << (int) 4;
    out << LineEditEmail->text();
    out << toMD5(LineEditPassword->text());
    out << "\n";

    qDebug() << "Bytes written: " << socket->bytesToWrite();
    qDebug() << "Status of Datastream" << out.status();

    email = LineEditEmail->text();

    QSettings s;
    s.setValue("UserEmail",email);

    disconnect(actionLogin,0,0,0);
    connect(actionLogin,SIGNAL(triggered()),this,SLOT(logout_triggered()));
}

// This gets called when the user clicks the sayButton (next to where
// they type text to send to the chat room):
void MainWindow::on_sayButton_clicked()
{
    // What did they want to say (minus white space around the string):
    QString message = sayLineEdit->text().trimmed();

    // Kills the Programm by this message
    if(message == "/exit")
    {
        MainWindow::close();
    }
    // Delete written text in the chatwindow
    else if(message == "/clear")
    {
        roomTextEdit->clear();
    }
    // Only send the text to the chat server if it's not empty:
    else if(!message.isEmpty())
    {
        QDataStream out(socket);
        //QString regi(" + reg->getUsername() + ":" + reg->getPassword() + "\n");
        //int sizeOfText = regi.size();

        out << (int) 3;
        out << ipv4.toString();
        out << QString("all");
        out << QString("none");
        out << message;
        out << "\n";

        qDebug() << "Bytes written: " << socket->bytesToWrite();
        qDebug() << "Status of Datastream" << out.status();

    }
    // Clear out the input box so they can type something else:
    sayLineEdit->clear();

    // Put the focus back into the input box so they can type again:
    sayLineEdit->setFocus();
}

// This function gets called whenever the chat server has sent us some text:
void MainWindow::readyRead()
{
    // We'll loop over every (complete) line of text that the server has sent us:
    while(socket->canReadLine())
    {

        QDataStream in(socket);

        int messageID;
        QString temp;

        in >> messageID;
        qDebug() << "messageID: " << messageID;

        if(messageID == 0)
        {
            int errorID;
            in >> errorID;

            qDebug() << "Errornumber: " << errorID;

            switch(errorID)
            {
                case 0: error->registrationFailed(); break;
                case 1: error->loginFailed(); break;
                case 2: error->sendFileFailedOffline(); break;
            }
        }
        else if(messageID == 2)
        {
            int stateID;
            in >> stateID;
            //in >> temp;

            qDebug() << "Current status: " << stateID;


            if(stateID == 1)
            {
                // Flip over to the chat page:
                stackedWidget->setCurrentWidget(chatPage);
                actionLogin->setText("Logout");
                connect(actionLogin,SIGNAL(triggered()),this,SLOT(logout_triggered()));

                sayLineEdit->setFocus();

                QString name;
                in >> name;
                QSettings s;
                s.setValue("Username",name);
                //sende anfrage nach der userliste
                QDataStream out(socket);
                //QString regi(" + reg->getUsername() + ":" + reg->getPassword() + "\n");
                //int sizeOfText = regi.size();

                out << (int) 5;
                out << (int) 1;
                out << this->email;
                out << "\n";
            }
            else if(stateID == 2)
            {


            }
        }
        else if(messageID == 3)
        {
            QString fromMail;
            QString toMail;
            QString room;
            QString message;

            in >> fromMail;
            in >> toMail;
            in >> room;
            in >> message;

            qDebug() << "A message from " << fromMail << " to " << toMail << endl
                     << "Room: " << room << endl
                     << "Message: " << message;


            // look if the user has an open tab in the chatwidget
            bool exist = false;
            for(int i = 0; i < cw->count(); i++)
            {
                if(fromMail == cw->tabText(i))
                {
                    // uhh the tab exist and we can write the text into the widget

                    // first we need access to the textfield in the specified tab
                    newTab *chat = (newTab*)cw->widget(i);
                    chat->writeInTextfield(message);

                    cw->raise();
                    exist = true;
                    // so the message is okay return here
                    break;
                }
            }

            // if we come to here then there is no tab for the user
            // we create on
            if(!exist)
            {
                cw->addTab(new newTab(0,socket),fromMail);
                qDebug() << "Tabs: " << cw->count();
                newTab *chat = (newTab*)cw->widget(cw->count()-1);
                cw->show();
                chat->writeInTextfield(message);
                cw->raise();
            }



        }
        else if(messageID == 5)
        {
            int reQuestID;
            in >> reQuestID;

            if(reQuestID == 3)
            {
                QMap<QString,QString> list;
                in >> list;

                QMapIterator<QString,QString>i(list);
                while (i.hasNext())
                {
                    i.next();

                    newUserAuthDialog *newUser = new newUserAuthDialog(this);
                    newUser->setEmailText(QString(i.key()));
                    newUser->setUsernametext(QString(i.value()));

                    newUser->show();
                    newUser->exec();


                    if(newUser->result())
                    {
                        //send message to server that the user accepts the other user to his list
                        qDebug() << "Client akzeptiert Freundesabfrage ab";
                        QDataStream out(socket);
                        out << (int) 5;
                        out << (int) 5;
                        out << email;
                        out << QString(i.key());
                        out << (int) 1;
                        out << "\n";
                    }
                    else
                    {
                        //send message to server that the user dont accept the other user
                        qDebug() << "Client lehnt Freundesabfrage ab";
                        QDataStream out(socket);
                        out << (int) 5;
                        out << (int) 5;
                        out << email;
                        out << QString(i.key());
                        out << (int) 0;
                        out << "\n";
                    }
                }

                qDebug() << "These Users wants to be a friend with you: " << list.size() << list.values();

            }
            else if(reQuestID == 6)
            {
                //get a new user
                //update the userlist
                QString user;
                in >> user;
                new QListWidgetItem(QPixmap(":/user.png"), user, userListWidget);
            }
            else if(reQuestID == 7)
            {
                int ok = 0;
                QString emailFromChoosedUser;

                in >> ok;
                in >> emailFromChoosedUser;

                if(ok == 1)
                {
                    QString ipFromUser;
                    in >> ipFromUser;

                    qDebug() << "User(" << ipFromUser << "==" << emailFromChoosedUser << ") accepted. So we can open the Connection";


                    // send an info that the server is now listening

                    QDataStream out(socket);
                    out << (int) 7;
                    out << this->email;
                    out << emailFromChoosedUser;
                    out << "\n";

                }
                else
                {
                    qDebug() << "User dont wats your fucking file!! ";
                    QMessageBox msgBox;
                    msgBox.setText("User dont wats your fucking file!!");
                    msgBox.setWindowTitle("Infomation");
                    msgBox.setIcon(QMessageBox::Information);
                    msgBox.exec();
                }
            }
            else if(reQuestID == 8)
            {
                // setup server and socket for file transfer
                fileSender = new FileTransferSender(this);
                fileSender->listen(QHostAddress::Any,4242);
                fileSender->setFilePath(this->filePath);


                qDebug() << "Is sender listening? " << fileSender->isListening();

            }
            else if(reQuestID == 9)
            {
                // Request to get offline messages
                // now get offline messages from friends
                QDataStream out(socket);
                out << (int) 5;
                out << (int) 8;
                out << this->email;
                out << "\n";
            }
            else if(reQuestID == 10)
            {
                QString fromEmail;
                QString fromUserIp;
                QString fromUser;
                QString filename;

                in >> fromEmail;
                in >> fromUserIp;
                in >> fromUser;
                in >> filename;

                newDataAuthDialog *newFile = new newDataAuthDialog(this);
                newFile->setEmailText(fromEmail);
                newFile->setUsernametext(fromUser);
                newFile->setFileText(filename);

                newFile->show();
                newFile->exec();


                if(newFile->result())
                {
                    //send message to server that the user accepts the other user to his list
                    qDebug() << "Client akzeptiert Datei von: " << fromUserIp;
                    QDataStream out(socket);
                    out << (int) 5;
                    out << (int) 6;
                    out << this->email; // Email from User who get the File Question
                    out << fromEmail; // Email from User who send the File Question
                    out << (int) 1;
                    out << "\n";

                    // now setup the tcpsocket and listen to the port 4242
                    fileReceiver = new FileTransferReceiver(this);

                    fileReceiver->connectToHost(QHostAddress(fromUserIp),4242);

                    // IMPORTANT NEED IP FROM SENDER
                    // fileReceiver->connectToHost();
                }
                else
                {
                    //send message to server that the user dont accept the other user
                    qDebug() << "Client lehnt Datei ab";
                    QDataStream out(socket);
                    out << (int) 5;
                    out << (int) 6;
                    out << this->email; // Email from User who get the File Question
                    out << fromEmail; // Email from User who send the File Question
                    out << (int) 0;
                    out << "\n";
                }
            }

        }
        else if(messageID == 6)
        {
            //get the Userlist after login
            qDebug() << "get the Userlist after login";
            QMap<QString, bool> userlist;
            in >> userlist;
            userListWidget->clear();

            QMapIterator<QString, bool> i(userlist);

            while(i.hasNext())
            {
                i.next();
                if(i.value())
                {
                    new QListWidgetItem(QPixmap(":/user.png"), i.key(), userListWidget);
                }
                else
                {
                    new QListWidgetItem(QPixmap(":/user_offline.png"), i.key(), userListWidget);
                }
            }

            qDebug() << userlist.size() << "User are copied to the list";

            out << (int) 5;
            out << (int) 4;
            out << email;
            out << "\n";
        }
        else if(messageID == 7)
        {
            int answerID;
            in >> answerID;

            if(answerID == 2)
            {
                //friend is Online
                qDebug() << "friend is online";
                QString _friend;
                in >> _friend;

                if(!checkUserInList(_friend))
                {
                    new QListWidgetItem(QPixmap(":/user.png"), _friend, userListWidget);
                }
                else
                {
                    getUserInList(_friend)->setIcon(QPixmap(":/user.png"));
                }
            }
            else if(answerID == 3)
            {
                // friend is offline
                qDebug() << "friend is offine";
                QString _friend;
                in >> _friend;

                getUserInList(_friend)->setIcon(QPixmap(":/user_offline.png"));
                statusBarMain->showMessage(_friend + " hat sich ausgeloggt");

            }
            else if(answerID == 4)
            {
                // ungelesene Nachrichten
                QMultiMap<int, QString> list;

                in >> list;
                int count_messages = (list.size()/4);
                qDebug() << "Anzahl ungelesener Nachrichten: " << count_messages;

                for(int i = 1; i <= count_messages; i++ )
                {
                    QList<QString> messageItem = list.values(i);
                    for (int j = 0; j < count_messages; ++j)
                    {
                        qDebug() << "Date: " << messageItem.at(0) << " Message: " << messageItem.at(1) << " FromEmail: " << messageItem.at(2) << "FromName: " << messageItem.at(3);
                        QString message = messageItem.at(0);
                        message.append("@");
                        message.append(messageItem.at(3));
                        message.append(": ");
                        message.append(messageItem.at(1));

                        /*cw->addTab(new newTab(0,socket),messageItem.at(2));
                        qDebug() << "Tabs: " << cw->count();
                        newTab *chat = (newTab*)cw->widget(cw->count()-1);
                        cw->show();
                        chat->writeInTextfield(message);
                        cw->raise();*/

                        // look if the user has an open tab in the chatwidget
                        bool exist = false;
                        for(int i = 0; i < cw->count(); i++)
                        {
                            if(messageItem.at(2) == cw->tabText(i))
                            {
                                // uhh the tab exist and we can write the text into the widget

                                // first we need access to the textfield in the specified tab
                                newTab *chat = (newTab*)cw->widget(i);
                                chat->writeInTextfield(message);

                                cw->raise();
                                exist = true;
                                // so the message is okay return here
                                break;
                            }
                        }

                        // if we come to here then there is no tab for the user
                        // we create on
                        if(!exist)
                        {
                            cw->addTab(new newTab(0,socket),messageItem.at(2));
                            qDebug() << "Tabs: " << cw->count();
                            newTab *chat = (newTab*)cw->widget(cw->count()-1);
                            cw->show();
                            chat->writeInTextfield(message);
                            cw->raise();
                        }
                    }
                }
            }
        }

        in >> temp;
        qDebug() << "Endzeichen gelesen";
        return;
        // Here's the line of text the server sent us (we use UTF-8 so
        // that non-English speakers can chat in their native language)
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        // These two regular expressions describe the kinds of messages
        // the server can send us:

        //  Normal messges look like this: "username:The message"
        QRegExp messageRegex("^([^:]+):(.*)$");

        // Any message that starts with "/users:" is the server sending us a
        // list of users so we can show that list in our GUI:
        QRegExp usersRegex("^/users:(.*)$");

        // A message that starts with this, will hold after that a binary file
        QRegExp fileRegex("^/dataFrom:(.*)$");

        // Is this a users message:
        if(usersRegex.indexIn(line) != -1)
        {
            // If so, udpate our users list on the right:
            QStringList users = usersRegex.cap(1).split(",");
            userListWidget->clear();

            foreach(QString user, users)
            {
                new QListWidgetItem(QPixmap(":/user.png"), user, userListWidget);
            }
        }
        else if(fileRegex.indexIn(line) != -1)
        {
            qDebug() << "Daten von: nach: " + fileRegex.cap(1);

            QByteArray data = socket->readAll();
            qDebug() << data.size();
            Dialog *filerecieve = new Dialog();
            filerecieve->binaryfile = data;
            qDebug() << filerecieve->binaryfile.size();

            QFileDialog *saveFileDialog = new QFileDialog();
            QString dir = saveFileDialog->getExistingDirectory(this, tr("Open Directory"),
                                                                "/home",
                                                                QFileDialog::ShowDirsOnly
                                                                | QFileDialog::DontResolveSymlinks);
            //saveFileDialog->show();
            qDebug() << "Wohin mit der Datei?";

                QFile MyFile( dir + "/test.txt");
                qDebug() << MyFile.fileName();
                if (MyFile.open(QIODevice::WriteOnly))
                {

                    MyFile.write(data);
                    qDebug() << data.size();
                    qDebug() << "Datei wurde geschrieben.";
                    MyFile.close();
                }

        }
        // Is this a normal chat message:
        else if(messageRegex.indexIn(line) != -1)
        {
            // If so, append this message to our chat box:
            QApplication::alert(this,10000);
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            roomTextEdit->append("<b>" + user + "</b>: " + message);
        }
    }
}

// This function gets called when our socket has successfully connected to the chat
// server. (see the connect() call in the MainWindow constructor).
void MainWindow::connected()
{
    qDebug() << "Verbindung zum Server hergestellt";
    statusBarMain->showMessage("Verbindung zum Server hergestellt");

    // And send our username to the chat server.
    //socket->write(QString("/me:" + userLineEdit->text() + "\n").toUtf8());
    ipv4 = socket->peerAddress();
    qDebug() << socket->errorString();
    qDebug() << "Info: " << ipv4.toString() << " ||| ";

    actionLogin->setVisible(true);
    actionRegistration->setVisible(true);
    actionAdd_User->setVisible(true);
    actionDelete_User->setVisible(true);
    actionCreate_Room->setVisible(true);
    actionDelete_Room->setVisible(true);
    actionSend_Data->setVisible(true);

    actionLogin->setEnabled(true);
    actionRegistration->setEnabled(true);
    actionAdd_User->setEnabled(true);
    actionDelete_User->setEnabled(true);
    actionCreate_Room->setEnabled(true);
    actionDelete_Room->setEnabled(true);
    actionSend_Data->setVisible(true);

    loginButton->setEnabled(true);
}

void MainWindow::wasDoubleClicked(QListWidgetItem *user)
{
    qDebug("DOUBLEClicked");
    if(!cw->isWindow())
    {
        qDebug() << "Erstelle Chatfenster";

        cw->show();
    }
    cw->show();
    if(!cw->existTab(user->text()))
    {
        cw->addTab(new newTab(0,socket),user->text());
    }

    cw->raise();
}


void MainWindow::setCountValue(QString newValue)
{
    QString value = QString::number(sayLineEdit->text().size());
    newValue = "Zeichen: " + value;// + sayLineEdit->text().size();
    charLabel->setText(newValue);
}

void MainWindow::data_send()
{

}

void MainWindow::on_actionRegistration_triggered()
{
    if(RegistrationMode)
    {
        Registration *reg = new Registration();

        reg->show();
        if(reg->exec())
        {
            qDebug() << "Ein neuer User wird registriert";
            qDebug() << "Seine EMail: " << reg->getEmail();
            qDebug() << "Sein Username: " << reg->getUsername();
            qDebug() << "Passwort1: " << reg->getPasswordFirst();
            qDebug() << "Passwort2: " << reg->getPasswordSecond();

            QDataStream out(socket);
            //QString regi(" + reg->getUsername() + ":" + reg->getPassword() + "\n");
            //int sizeOfText = regi.size();
            QString email(reg->getEmail());
            QString username(reg->getUsername());
            QString passwordFi(reg->getPasswordFirst());
            QString passwordSe(reg->getPasswordSecond());

            QString emailPatt = "\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b";

            QRegExp rx(emailPatt);
            rx.setCaseSensitivity(Qt::CaseInsensitive);
            rx.setPatternSyntax(QRegExp::RegExp);

            if(!rx.exactMatch(email))
            {
                QMessageBox msgBox;
                msgBox.setText("Email-Address is not vaild!");
                msgBox.setWindowTitle("Infomation");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.exec();
                return;
            }

            if(passwordFi != passwordSe)
            {
                QMessageBox msgBox;
                msgBox.setText("Passwords are not identical!");
                msgBox.setWindowTitle("Infomation");
                msgBox.setIcon(QMessageBox::Information);
                msgBox.exec();
                return;
            }

            out << (int) 1;
            //out << (int) sizeOfText;
            out << email;
            out << username;
            out << passwordFi;
            out << "\n";

            QChar * ch = email.data();

            while(!ch->isNull())
            {
                qDebug() << ch->unicode();
                ch++;
            }
            //socket->write(QString("/registration:" + reg->getUsername() + ":" + reg->getPassword() + "\n").toUtf8());
            RegistrationMode = false;
            //registrationTimer->start(1800000);
            registrationTimer->start(1800);
            connect(registrationTimer,SIGNAL(timeout()),this,SLOT(changeRegistrationMode()));
        }

        delete reg;
    }
    else
    {
        qDebug() << "Registrierung erst in 30 Minuten wieder m�glich";
        qDebug() << "Bitte warten...";
    }
}

void MainWindow::changeRegistrationMode()
{
    registrationTimer->stop();
    RegistrationMode = true;
}



void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog *setting = new SettingsDialog(this);

    setting->show();
    if(setting->exec())
    {
        //qDebug() << setting->getServerAddress();
        setting->saveSettings();
    }


}

QString MainWindow::toMD5(QString text)
{
   return QString(QCryptographicHash::hash((text.toUtf8()),QCryptographicHash::Md5).toHex());
}

void MainWindow::socketError(QAbstractSocket::SocketError error)
{
    qDebug() << "Socketerror: " << error;
    if(error == QAbstractSocket::RemoteHostClosedError)
    {
        actionLogin->setText("Login");
        disconnect(actionLogin,0,0,0);
        connect(actionLogin,SIGNAL(triggered()),this,SLOT(on_actionLogin_triggered()));
        stackedWidget->setCurrentWidget(loginPage);

        userListWidget->clear();
        cw->close();
        QMessageBox msgBox;
        msgBox.setText("Server hat die Verbindung abgebrochen");
        msgBox.setWindowTitle("Infomation");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.exec();
    }
}

void MainWindow::on_actionConnect_triggered()
{
    QSettings s;
    qDebug() << "Verbindung zu: " << s.value("ServerAddress").toString() << " Port: " << s.value("ServerPort").toInt();
    socket->connectToHost(s.value("ServerAddress").toString(),s.value("ServerPort").toInt());
    //socket->connectToHost("localhost", 4201);
}

void MainWindow::on_actionLogin_triggered()
{
    qDebug() << "ActionLogin getriggerd";
    emit on_loginButton_clicked();
}

void MainWindow::logout_triggered()
{
    qDebug() << "Logout";
    statusBarMain->showMessage("Logout");
    QDataStream out(socket);

    out << (int) 2;
    out << (int) 3;
    out << email;
    out << "\n";
    socket->close();

    actionLogin->setText("Login");
    disconnect(actionLogin,0,0,0);
    connect(actionLogin,SIGNAL(triggered()),this,SLOT(on_actionLogin_triggered()));

    actionLogin->setVisible(false);
    actionRegistration->setVisible(false);
    actionAdd_User->setVisible(false);
    actionDelete_User->setVisible(false);
    actionCreate_Room->setVisible(false);
    actionDelete_Room->setVisible(false);

    loginButton->setEnabled(false);
    cw->clear();
    cw->close();
    stackedWidget->setCurrentWidget(loginPage);
}

void MainWindow::on_actionAdd_User_triggered()
{
    DialogAddUser *dia = new DialogAddUser(this);

    dia->show();
    if(dia->exec())
    {
        QDataStream out(socket);

        QString email(dia->getEmail());

        out << (int) 5;
        out << (int) 2;
        out << this->email;
        out << email;
        out << "\n";
    }

}

void MainWindow::on_actionDelete_User_triggered()
{
    DialogDeleteFriendship *dia = new DialogDeleteFriendship(this);

    dia->show();
    if(dia->exec())
    {
        QDataStream out(socket);

        QString email(dia->getEmail());

        out << (int) 5;
        out << (int) 7;
        out << this->email;
        out << email;
        out << "\n";

        //QList<QListWidgetItem*> list = userListWidget->findItems(email,Qt::MatchExactly);

        //qDebug() << list.size() << list.value(0)->text();
        //userListWidget->removeItemWidget(list.value(0));
        //userListWidget->takeItem()

        for(int i = 0; i < userListWidget->count(); i++)
        {
            if(userListWidget->item(i)->text() == email)
            {
                delete userListWidget->takeItem(i);
            }
        }
    }
}

void MainWindow::on_actionCreate_Room_triggered()
{

}

void MainWindow::on_actionDelete_Room_triggered()
{

}

void MainWindow::on_actionQuit_triggered()
{
    qDebug() << "Programm cloesd";

    qDebug() << "Logout";
    statusBarMain->showMessage("Logout");
    QDataStream out(socket);

    out << (int) 2;
    out << (int) 3;
    out << email;
    out << "\n";
    socket->close();

    this->close();
}

bool MainWindow::checkUserInList(QString user)
{
    for(int i=0; i < userListWidget->count(); i++)
    {
        if(user == userListWidget->item(i)->text())
        {
            return true;
        }
    }

    return false;
}

QListWidgetItem* MainWindow::getUserInList(QString user)
{
    for(int i=0; i < userListWidget->count(); i++)
    {
        if(user == userListWidget->item(i)->text())
        {
            return userListWidget->item(i);
        }
    }

    return 0;
}

void MainWindow::on_actionSend_Data_triggered()
{
    Dialog *filesend = new Dialog();
    qDebug() << userListWidget->count();
    for(int i = 0; i < userListWidget->count(); i++)
    {
        QString itemData = userListWidget->item(i)->text();
        filesend->listWidget->addItem(itemData);
    }
    filesend->show();
    if(filesend->exec())
    {
        // so first we need the choosed user if online or not
        QString toUser = filesend->listWidget->item(filesend->listWidget->currentRow())->text();//user@host
        QString fileName = filesend->datei->text();
        this->filePath = fileName;
        QDataStream out(socket);

        out << (int) 6;
        out << toUser;
        out << this->email;
        out << fileName;
        out << "\n";

        //socket->write(QString("/dataTo:" + toUser + "\n").toUtf8());
        //qint64 anzahl = socket->write(filesend->binaryfile);
        //qDebug() << anzahl;



    }

    delete filesend;
}
