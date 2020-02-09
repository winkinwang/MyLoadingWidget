#include "MyLoadingWidget.h"
#include "QMovie"
#include "QDebug"
#include "QHBoxLayout"

#define DEFAULT_WIDGET_WIDTH 300
#define DEFAULT_WIDGET_HIGHT 300

MyLoadingWidget::MyLoadingWidget(QWidget*parent):
    QWidget(parent)
{
    this->setFixedSize(DEFAULT_WIDGET_WIDTH,DEFAULT_WIDGET_HIGHT);
    setWindowOpacity(0.9); //设置透明用；

//    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
    //取消对话框标题
//    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    //取消对话框标题和边框
    //this->setAutoFillBackground(true);
    this->setContentsMargins(0,0,0,0);

//    this->setStyleSheet("background-color:#f0f;border-radius:10px;");

    mLabel = new QLabel(this);
    mLabel->setFixedSize(this->size());
    mLabel->setContentsMargins(0,0,0,0);
//    mLabel->setScaledContents(true);

    mMovie = new QMovie();
    mLabel->setMovie(mMovie);
    mMovie->setScaledSize(this->size());
}

MyLoadingWidget::~MyLoadingWidget()
{
    delete mLabel;
    delete mMovie;
}

void MyLoadingWidget::start() {
    QString gitFile = ":/res/res/loading.gif";
    //gitFile = "D:/work_space/QT_space/res/loading.gif"

    mMovie->setFileName(gitFile);
    mMovie->start();
}

void MyLoadingWidget::stop() {
    mMovie->stop();
}


//event begin
void MyLoadingWidget::resizeEvent(QResizeEvent *event) {
    int widgetWidth = event->size().width();
    int widgetHight = event->size().height();

    printf("resize enter w:%d h:%d\n", widgetWidth, widgetHight);
    mLabel->setFixedSize(event->size());
    mMovie->setScaledSize(event->size());
}
//event end


void MyLoadingWidget::test(QWidget *widget) {
    //实例化loading窗口
    MyLoadingWidget *w = new MyLoadingWidget(widget);
//    w->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    w->setWindowModality(Qt::ApplicationModal);
//    w->move(880,450);
    w->start();
    w->setFixedSize(700, 800);
    w->show();
}
