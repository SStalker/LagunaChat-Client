#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDebug>
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    QSettings s;

    ui->lineEditServerAddress->setText(s.value("ServerAddress").toString());
    ui->comboBoxServerPort->setCurrentText(s.value("ServerPort").toString());

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
}

QString SettingsDialog::getServerAddress()
{
    return serverAddress;
}
