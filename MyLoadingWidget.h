#ifndef MYLOADINGWIDGET_H
#define MYLOADINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include "QLabel"
#include "QFrame"
#include "QResizeEvent"

namespace Ui {
class MyLoadingWidget;
}

class MyLoadingWidget : public QWidget
{
    Q_OBJECT
public:
    MyLoadingWidget(QWidget *parent = 0);
    ~MyLoadingWidget();

    static void test(QWidget *parent);


private:
    virtual void resizeEvent(QResizeEvent *event);

public slots:


signals:
    void loading();

private:
    Ui::MyLoadingWidget *ui;
    QMovie *movie;
    QLabel *label;
    QLabel * tip_label;
    QFrame * background;
    QTimer *timer ;
};


#endif // MYLOADINGWIDGET_H
