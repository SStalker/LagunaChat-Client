#include "chatwidget.h"
#include "ui_chatwidget.h"
#include "newtab.h"

#include <QDebug>
#include <QSettings>

ChatWidget::ChatWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ChatWidget)
{
    ui->setupUi(this);

    connect(this,SIGNAL(currentChanged(int)),this,SLOT(changedTab(int)));
    connect(this,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));
}

ChatWidget::~ChatWidget()
{
    delete ui;
}

void ChatWidget::changedTab(int i)
{
    qDebug() << "Changed to Tab Nr." << i;
}

void ChatWidget::tabInserted(int index)
{
    qDebug() << "Yay a new Tab. Index: " << index;

    newTab *tab = (newTab*)widget(index);
    QSettings s;
    tab->setFriend(tabText(index));
    tab->setUser(s.value("UserEmail").toString());

    this->setCurrentIndex(index);
}

void ChatWidget::closeTab(int index)
{
    qDebug() << "Tab No." << index << " should closed now";
    removeTab(index);

    if(count() == 0)
    {
        this->close();
    }
}

bool ChatWidget::existTab(QString tabname)
{
    for(int i = 0; i < count(); i++)
    {
        if(tabText(i) == tabname)
        {
            return true;
        }

    }
    return false;
}
