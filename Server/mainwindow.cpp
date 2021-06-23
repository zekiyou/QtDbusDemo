#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "echointerface.h"
#include <QDebug>

class MainWindowPrivate
{
    Q_DECLARE_PUBLIC(MainWindow)

public:
        int count;
        QStandardItemModel *model;
        MainWindow *q_ptr;
        bool LoadPlugin();
        EchoInterface *echoInterface;
        MainWindowPrivate(MainWindow* parent)
        {
            count = 0;
            model = new QStandardItemModel();
            q_ptr=parent;
        }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , d_ptr(new MainWindowPrivate(this))
    , ui(new Ui::MainWindow)
{
    Q_D(MainWindow);

    ui->setupUi(this);
    //获得主窗口的大小
    int width = this->width();
    int height = this->height();
    //调整tableView窗口大小和主窗口一致
    ui->tableView->resize(width, height);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //设置表格样式 
    d->model->setColumnCount(7);
    d->model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
    d->model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("年龄"));
    d->model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("身份证号"));
    d->model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("手机号"));
    d->model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("住址"));
    d->model->setHeaderData(5,Qt::Horizontal,QString::fromLocal8Bit("体温"));
    d->model->setHeaderData(6,Qt::Horizontal,QString::fromLocal8Bit("是否放行"));

    ui->tableView->setModel(d->model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::server_get(QString name , int age , QString id , QString tel , QString adress , double temperature)
{
    Q_D(MainWindow);

    d->model->setItem(d->count,0,new QStandardItem(name));
    d->model->setItem(d->count,1,new QStandardItem(QString::number(age)));
    d->model->setItem(d->count,2,new QStandardItem(id));
    d->model->setItem(d->count,3,new QStandardItem(tel));
    d->model->setItem(d->count,4,new QStandardItem(adress));
    d->model->setItem(d->count,5,new QStandardItem(QString::number(temperature)));

    if (37.2 <= temperature ) {
        d->model->setItem(d->count, 6, new QStandardItem(QString("否")));
        emit send_to_client_error();
    }

    if (temperature < 37.2) {
        d->model->setItem(d->count , 6, new QStandardItem(QString("是")));
        emit send_to_client_ok();
    }

    d->count++;

    if(d->LoadPlugin()){
        d->echoInterface->echo(QString::number(temperature));
    }

}


bool MainWindowPrivate::LoadPlugin()
{

    bool ret = true;
    //获取当前应用程序所在路径
    QDir pluginsDir(qApp->applicationDirPath());
    #if defined(Q_OS_WIN)
        if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() =="release"){
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #elif defined(Q_OS_MAC)
        if (pluginsDir.dirName() == "MacOS")
        {
            pluginsDir.cdUp();
            pluginsDir.cdUp();
            pluginsDir.cdUp();
        }
    #elif defined(Q_OS_LINUX)
        pluginsDir.cdUp();
    #endif
        //切换到插件目录
        pluginsDir.cd("plugins");
        //遍历plugins目录下所有文件
        foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
            QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
            QObject *plugin = pluginLoader.instance();
            if (plugin) {
                //插件名称
                QString pluginName = plugin->metaObject()->className();
                //对插件初始化
                if (pluginName == "EchoPlugin") {
                    echoInterface = qobject_cast<EchoInterface*>(plugin);
                    if (echoInterface)
                        ret =  true;
                    break;
                }
                else {
                    ret = false;
                }
            }
        }
        return ret;
}
