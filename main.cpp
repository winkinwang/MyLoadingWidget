#include <QApplication>
#include "MyLoadingWidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    printf("main\n");

//    MyLoadingWidget *w = new MyLoadingWidget(nullptr);
//    w->show();
    MyLoadingWidget::test(nullptr);

    return a.exec();
}
