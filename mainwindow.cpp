#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //1.stackedWidget的页面使用，使用索引值来做。
    {//====================================
    int m;
    m=ui->stackedWidget->count();//显示总页数
    qDebug()<<m;
    ui->tabWidget->setCurrentIndex(0);
    }//===================================
//    connect(ui->pushButton,SIGNAL(clicked()),ui->stackedWidget,SLOT(setCurrentIndex(0));//button的点击的信号是怎样的。
//    connect(ui->pushButton_2,SIGNAL(clicked())),ui->stackedWidget,SLOT(setCurrentIndex(1));
//    connect(ui->pushButton_3,SIGNAL(clicked())),ui->stackedWidget,SLOT(setCurrentIndex(2));
    //2.QDockWidget的使用，好好研究下，包括，停靠关系,和使用代码进行布局
    {
//        QTextEdit *title =new QTextEdit(this);
//        title->setText("Main Window");
//        title->setAlignment(Qt::AlignCenter);
//        this->setCentralWidget(title);//居中全部显示

        QDockWidget *dock = new QDockWidget(tr("DockWindow 1"),this);
        dock->setFeatures(QDockWidget::DockWidgetMovable);
        dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        QTextEdit *title1 = new QTextEdit();
        title1->setText("Window 1");
        dock->setWidget(title1);
       // this->addDockWidget(Qt::LeftDockWidgetArea,dock);
        ui->tabWidget->addTab(dock,"dock");

//        dock = new QDockWidget(tr("DockWindow 2"),this);
//        dock->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetClosable);
//        QTextEdit *title2 = new QTextEdit();
//        title2->setText("Window 2");
//        dock->setWidget(title2);
//        this->addDockWidget(Qt::LeftDockWidgetArea,dock);

//        dock = new QDockWidget(tr("DockWindow 3"),this);
//        dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
//        QTextEdit *title3 = new QTextEdit();
//        title3->setText("Window 3");
//        dock->setWidget(title3);
//        this->addDockWidget(Qt::BottomDockWidgetArea,dock);
        //ui->tabWidget->addTab();
      //  ui->tabWidget->setCurrentIndex(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//1.stackedWidget
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()//1.stackedWidget
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()//1.stackedWidget
{
    int n=ui->stackedWidget->currentIndex();
    n++;
    qDebug()<<n;
    if(n==(ui->stackedWidget->count()))
    {
        n=0;
    }
    ui->stackedWidget->setCurrentIndex(n);


}
