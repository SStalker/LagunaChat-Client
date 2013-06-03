#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QTabWidget>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit ChatWidget(QWidget *parent = 0);
    ~ChatWidget();
    bool existTab(QString tabname);
    
private:
    Ui::ChatWidget *ui;

private slots:
    void changedTab(int i);
    void closeTab(int index);

protected:
    void tabInserted(int index);
};

#endif // CHATWIDGET_H
