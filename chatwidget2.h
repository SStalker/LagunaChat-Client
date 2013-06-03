#ifndef CHATWIDGET2_H
#define CHATWIDGET2_H

#include <QWidget>
#include <QTabWidget>

namespace Ui {
class ChatWidget2;
}

class ChatWidget2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChatWidget2(QWidget *parent = 0);
    ~ChatWidget2();
    QTabWidget *tab;
private:
    Ui::ChatWidget2 *ui;
};

#endif // CHATWIDGET2_H
