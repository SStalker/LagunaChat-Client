#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include "ui_dialog.h"


class Dialog : public QDialog, public Ui::Dialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    QByteArray binaryfile;
    QDataStream input;
    QFile fileToSend;

    
private:
    QFileDialog openFileDialog;
    QStringList fileList;



private slots:
    void openDialog();
};

#endif // DIALOG_H
