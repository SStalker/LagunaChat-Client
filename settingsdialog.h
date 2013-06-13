#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
    QString getServerAddress();
    void saveSettings();
    
private:
    Ui::SettingsDialog *ui;

    QString serverAddress;
private slots:
    void choosePathForDownloads();

};

#endif // SETTINGSDIALOG_H
