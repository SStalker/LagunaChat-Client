#include "chatwidget2.h"
#include "ui_chatwidget2.h"

ChatWidget2::ChatWidget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWidget2)
{
    ui->setupUi(this);

    this->tab = ui->tabWidget;

}

ChatWidget2::~ChatWidget2()
{
    delete ui;
}
