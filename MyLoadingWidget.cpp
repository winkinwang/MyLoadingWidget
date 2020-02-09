#include "MyLoadingWidget.h"
#include "QMovie"
#include "QDebug"
#include "QHBoxLayout"

//MyLoadingWidget::MyLoadingWidget(QWidget *parent) :
//    QWidget(parent)
//{
//    this->setFixedSize(200,200);
//    background = new QFrame(this);
//    background->setStyleSheet("background-color:#fff;border-radius:10px;");
//    background->setGeometry(0, 50, 200, 150);
//    label = new QLabel(background);
//    label->setGeometry(0, 0, 200, 150);
//    movie = new QMovie("../res/loding.gif");
//    movie->setScaledSize(QSize(200,150));
//    label->setScaledContents(true);
//    label->setMovie(movie);
//    movie->start();
//    qDebug()<<"loading";
//    connect(this,SIGNAL(loading()),this,SLOT(close()));
//}

#define DEFAULT_WIDGET_WIDTH 300
#define DEFAULT_WIDGET_HIGHT 300

MyLoadingWidget::MyLoadingWidget(QWidget*parent):
    QWidget(parent)
{
    QString gitFile = ":/res/res/loading.gif";
    //"D:/work_space/QT_space/res/loading.gif"

//    QHBoxLayout

    label = new QLabel(this);
    label->setText("I am here");
    this->setFixedSize(DEFAULT_WIDGET_WIDTH,DEFAULT_WIDGET_HIGHT);
    setWindowOpacity(0.9); //设置透明用；
//    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);

    //取消对话框标题
//    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    //取消对话框标题和边框
    //this->setAutoFillBackground(true);
    this->setContentsMargins(0,0,0,0);

    label->setFixedSize(this->size());
    label->setContentsMargins(0,0,0,0);
//    QPalette palette;
//    QBrush brush(QPixmap("D:/work_space/QT_space/res/loading.gif"));
//    palette.setBrush(QPalette::Background,brush);
//    this->setPalette(palette);
    movie = new QMovie(gitFile);
    label->setMovie(movie);
    movie->setScaledSize(this->size());
    movie->start();
}

void MyLoadingWidget::resizeEvent(QResizeEvent *event) {
    int widgetWidth = event->size().width();
    int widgetHight = event->size().height();

    printf("resize enter w:%d h:%d\n", widgetWidth, widgetHight);
    label->setFixedSize(event->size());
    movie->setScaledSize(event->size());
}

MyLoadingWidget::~MyLoadingWidget()
{
    //一定要delete界面元素,不然会留下现一个透明方框
    delete background;
    delete label;
    delete movie;
    delete ui;
}


void MyLoadingWidget::test(QWidget *widget) {
    //实例化loading窗口
    MyLoadingWidget *w = new MyLoadingWidget(widget);
//    w->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    w->setWindowModality(Qt::ApplicationModal);
//    w->move(880,450);
    w->setFixedSize(700, 800);
    w->show();
}
