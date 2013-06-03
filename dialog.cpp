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
    if(openFileDialog.exec())
    {
        fileList = openFileDialog.selectedFiles();
        qDebug() << fileList.first();
        datei->setText(fileList.first());

        QFile file(fileList.first());
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);//binaryfile += file.readLine();
        in >> binaryfile;
        file.close();

        qDebug() << binaryfile.size();
    }
}
