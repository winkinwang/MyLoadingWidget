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

    void start();

    void stop();

    static void test(QWidget *parent);
private:
    virtual void resizeEvent(QResizeEvent *event);

private:
    QMovie *mMovie;
    QLabel *mLabel;
};


#endif // MYLOADINGWIDGET_H
