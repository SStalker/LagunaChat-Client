#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>
#include <QSettings>
#include <QFileDialog>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    QSettings s;

    ui->lineEditServerAddress->setText(s.value("ServerAddress").toString());
    ui->comboBoxServerPort->setCurrentText(s.value("ServerPort").toString());
    ui->lineEditFileTransferPath->setText(s.value("FileTransferPath").toString());

    // SET THE CONNECTS
    connect(ui->pushButton_FileTransfer_Path,SIGNAL(clicked()),this,SLOT(choosePathForDownloads()));

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::saveSettings()
{
    QSettings s;
    s.setValue("ServerAddress",ui->lineEditServerAddress->text());
    s.setValue("ServerPort",ui->comboBoxServerPort->currentText());
    s.setValue("FileTransferPath",ui->lineEditFileTransferPath->text());
}

QString SettingsDialog::getServerAddress()
{
    return serverAddress;
}

void SettingsDialog::choosePathForDownloads()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Download Directory"),
                                                    "/home",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->lineEditFileTransferPath->setText(dir);

}
