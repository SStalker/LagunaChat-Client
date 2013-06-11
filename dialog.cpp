#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    connect(Button1,SIGNAL(clicked()),this,SLOT(openDialog()));
}

void Dialog::openDialog()
{
    QString filePath = QFileDialog::getOpenFileName(this,tr("Open File"), "/home");

    datei->setText(filePath);

    QFile file(filePath);
    qDebug() <<file.fileName();
    file.open(QIODevice::ReadOnly);
    //QDataStream in(&file);//binaryfile += file.readLine();
    //in >> binaryfile;
    //binaryfile = file.readAll();
    qDebug() << "Size of file: " << file.size() << " bytes";
    file.close();
}
