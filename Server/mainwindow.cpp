#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //获得主窗口的大小
    int width = this->width();
    int height = this->height();
    //调整tableView窗口大小和主窗口一致
    ui->tableView->resize(width,height);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格样式
    model = new QStandardItemModel();
    model->setColumnCount(7);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("年龄"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("身份证号"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("手机号"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("住址"));
    model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("体温"));
    model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("是否放行"));
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::server_get(QString name , int age , QString id , QString tel , QString adress , double temperature)
{
    model->setItem(count,0,new QStandardItem(name));
    model->setItem(count,1,new QStandardItem(QString::number(age)));
    model->setItem(count,2,new QStandardItem(id));
    model->setItem(count,3,new QStandardItem(tel));
    model->setItem(count,4,new QStandardItem(adress));
    model->setItem(count,5,new QStandardItem(QString::number(temperature)));
    if(temperature >= 37.2){
        model->setItem(count,6,new QStandardItem(QString("否")));
        emit send_to_client_error();
    }
    if(temperature < 37.2){
        model->setItem(count,6,new QStandardItem(QString("是")));
        emit send_to_client_ok();
    }
    count++;
}


