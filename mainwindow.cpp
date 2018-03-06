#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextEdit>
#include <QDockWidget>
#include <QLabel>

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
        ui->tabWidget->setCurrentIndex(1);
    }

    //4.mdiArea使用
    {//====================================
        QTextEdit *windows1 = new QTextEdit;
        windows1->setHtml("C");
        ui->mdiArea->addSubWindow(windows1);

        QTextEdit *windows2 = new QTextEdit;
        windows2->setHtml("C++");
        ui->mdiArea->addSubWindow(windows2);

        QTextEdit *windows3 = new QTextEdit;
        windows3->setHtml("Java");
        ui->mdiArea->addSubWindow(windows3);

        QTextEdit *newWindows = new QTextEdit;
        newWindows->setHtml("New Windows!");
        ui->mdiArea->addSubWindow(newWindows);

        QLabel *a = new QLabel;
        a->setText("hello world");
        ui->mdiArea->addSubWindow(a);


        ui->mdiArea->cascadeSubWindows();
        ui->tabWidget->setCurrentIndex(2);
    }//===================================



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



//void MainWindow::on_btnAdd_clicked()
//{
//    QTextEdit *newWindows = new QTextEdit;
//    newWindows->setHtml("New Windows!");
//    ui->mdiArea->addSubWindow(newWindows);
//}



void MainWindow::on_pushButton_4_clicked()//打开上一个窗口 4.mdiArea使用
{
    ui->mdiArea->activatePreviousSubWindow();
}

void MainWindow::on_pushButton_5_clicked()//打开下一个窗口 4.mdiArea使用
{
    ui->mdiArea->activateNextSubWindow();
}

void MainWindow::on_pushButton_6_clicked()//关闭当前窗口 4.mdiArea使用
{
    ui->mdiArea->closeActiveSubWindow();

}

void MainWindow::on_pushButton_7_clicked()//关闭所有窗口 4.mdiArea使用
{
     ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_pushButton_8_clicked()//该功能有待发现，新建一个窗口 4.mdiArea使用
{
//    QTextEdit *windows9 = new QTextEdit;
//    windows9->setHtml("C++++++++++11111111");
//    ui->mdiArea->addSubWindow(windows9);//主要问题可能是要重新刷新一下窗口，才会显示。
}
