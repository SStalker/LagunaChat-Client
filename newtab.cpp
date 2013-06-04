#include "newtab.h"
#include "ui_newtab.h"

#include <QDataStream>
#include <QDateTime>
#include <QSettings>
#include <QMap>
#include <QMapIterator>

#include <QTextBlock>

newTab::newTab(QWidget *parent, QTcpSocket *socket) :
    QWidget(parent),
    ui(new Ui::newTab)
{
    ui->setupUi(this);

    this->sock = socket;

    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(writeMessage()));

    //player = new QMediaPlayer;
    //player->setMedia(QUrl("qrc:/pony.wav"));
    //player->setVolume(100);
}

newTab::~newTab()
{
    //delete player;
    delete ui;
}

void newTab::writeMessage()
{
    QString text = ui->lineEdit->text();

    if(text != "")
    {
        ui->lineEdit->setText("");

        qDebug() << "Text to send: " << text ;

        QDataStream out(sock);

        out << (int) 3;
        out << this->user;
        out << this->friend_;
        out << QString("Room");
        out << text;
        out << "\n";

        text = setSmileys(text);
        QSettings s;
        QString localtext = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + "@" + s.value("Username").toString() + ": " + text ;
        ui->textEdit->append(localtext);

        // Now we should log the Data

       /* int lines = ui->textEdit->document()->lineCount();
        qDebug() << lines;
        if(lines == 3 || lines == 6)
        {
            ui->textEdit->moveCursor(QTextCursor::StartOfBlock);
        }*/
        //player->play();
        //player->setPosition(0);
   }
}

void newTab::setUser(QString mail)
{
    qDebug() << "setUser: " << mail;
    this->user = mail;
}
void newTab::setFriend(QString mail)
{
    qDebug() << "setFriend: " << mail;
    this->friend_ = mail;
}

void newTab::writeInTextfield(QString text)
{
    ui->textEdit->append(setSmileys(text));

    QApplication *app = (QApplication*) QApplication::instance();
    app->alert(0);
}

QString newTab::setSmileys(QString text)
{
    QMap<QString, QString> smileys;
    smileys[":-)"] = "<img src=':/greensmilie_set/icon_smile.gif'>";
    smileys[":)"] = "<img src=':/greensmilie_set/icon_smile.gif'>";

    smileys[":-("] = "<img src=':/greensmilie_set/icon_nosmile.gif'>";
    smileys[":("] = "<img src=':/greensmilie_set/icon_nosmile.gif'>";

    smileys[";-)"] = "<img src=':/greensmilie_set/icon_wink.gif'>";
    smileys["'-)"] = "<img src=':/greensmilie_set/icon_wink.gif'>";
    smileys[";)"] = "<img src=':/greensmilie_set/icon_wink.gif'>";

    smileys[":-|"] = "<img src=':/greensmilie_set/icon_neutral.gif'>";
    smileys[":|"] = "<img src=':/greensmilie_set/icon_neutral.gif'>";

    smileys[":->"] = "<img src=':/greensmilie_set/icon_fies.gif'>";
    smileys[">:->"] = "<img src=':/greensmilie_set/icon_fies.gif'>";
    smileys[">;->"] = "<img src=':/greensmilie_set/icon_fies.gif'>";
    smileys[":-O"] = "<img src=':/greensmilie_set/icon_eek.gif'>";
    smileys[":-o"] = "<img src=':/greensmilie_set/icon_erschreckt.gif'>";

    smileys[":-D"] = "<img src=':/greensmilie_set/icon_biggrin.gif'>";
    smileys[":D"] = "<img src=':/greensmilie_set/icon_biggrin.gif'>";

    smileys[":-X"] = "<img src=':/greensmilie_set/icon_stumm.gif'>";
    smileys[":X"] = "<img src=':/greensmilie_set/icon_stumm.gif'>";

    smileys[":-P"] = "<img src=':/greensmilie_set/icon_razz.gif'>";
    smileys[":P"] = "<img src=':/greensmilie_set/icon_razz.gif'>";

    QMapIterator<QString, QString> i(smileys);
    while(i.hasNext())
    {
        i.next();
        int j = 0;
        while((j = text.indexOf(i.key(),j)) != -1)
        {
            // get the position
            qDebug() << "Smiley gefunden an Stelle: " << j;
            text.replace(i.key(),i.value());
            ++j;
        }
    }
    return text;
}
