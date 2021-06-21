#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDBusConnection::sessionBus().connect("com.qdbus.server", "/com/qdbus/server", "com.qdbus.server", "send_to_client_ok", this, SLOT(client_get_ok(void)));
    QDBusConnection::sessionBus().connect("com.qdbus.server", "/com/qdbus/server", "com.qdbus.server", "send_to_client_error", this, SLOT(client_get_error(void)));

    id_exp.setPattern("^[1-9]\\d{5}(18|19|([23]\\d))\\d{2}((0[1-9])|(10|11|12))(([0-2][1-9])|10|20|30|31)\\d{3}[0-9Xx]$");
    tel_exp.setPattern("^1(3[0-9]|5[0-3,5-9]|7[1-3,5-8]|8[0-9])\\d{8}$");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //绑定QGSetting与xml
    m_settings = new QGSettings("com.QGSettingDemo.test","/com/QGSettingDemo/test/");

    //获取QGSetting发出的KEY值改变信号,在界面同步更新
    connect (m_settings,&QGSettings::changed,[=](const QString key)
    {
        if("name" == key)
        {
            QString name = m_settings->get("name").toString();
            ui->lineEdit_name->setText(name);
        }

        if("age" == key)
        {
            QString age = m_settings->get("age").toString();
            ui->lineEdit_age->setText(age);
        }

        if("id" == key)
        {
            QString id = m_settings->get("id").toString();
            ui->lineEdit_id->setText(id);
        }

        if("tel" == key)
        {
            QString tel = m_settings->get("tel").toString();
            ui->lineEdit_tel->setText(tel);
        }

        if("adress" == key)
        {
            QString adress = m_settings->get("adress").toString();
            ui->lineEdit_adress->setText(adress);
        }

        if("temperature" == key)
        {
            QString temperature = m_settings->get("temperature").toString();
            ui->lineEdit_temperature->setText(temperature);
        }

    });

    do{
        if(false == ui->lineEdit_name->text().isEmpty())
        {
            QString name = ui->lineEdit_name->text();
            if(m_settings)
            {
                m_settings->trySet("name",name);
            }
        }else {
            m_dialog = new Dialog(this);
            m_dialog->setLabel("请输入姓名");
            m_dialog->show();
            break;
        }


        if( ui->lineEdit_age->text().toInt() > 0 )
        {
            int age = ui->lineEdit_age->text().toInt();
            if(m_settings)
            {
                m_settings->trySet("age",age);
            }
        }else {
            m_dialog = new Dialog(this);
            m_dialog->setLabel("请输入正确年龄");
            m_dialog->show();
            break;
        }

        if(id_exp.exactMatch(ui->lineEdit_id->text()))
        {
            QString id = ui->lineEdit_id->text();
            if(m_settings)
            {
                m_settings->trySet("id",id);
            }
        }else {
            m_dialog = new Dialog(this);
            m_dialog->setLabel("请输入正确的身份证号");
            m_dialog->show();
            break;
        }

        if( tel_exp.exactMatch(ui->lineEdit_tel->text()))
        {
            QString tel = ui->lineEdit_tel->text();
            if(m_settings)
            {
                m_settings->trySet("tel",tel);
            }
        }else {
            m_dialog = new Dialog(this);
            m_dialog->setLabel("请输入正确的手机号");
            m_dialog->show();
            break;
        }

        if(false == ui->lineEdit_tel->text().isEmpty())
        {
            QString adress = ui->lineEdit_adress->text();
            if(m_settings)
            {
                m_settings->trySet("adress",adress);
            }
        }else {
            m_dialog = new Dialog(this);
            m_dialog->setLabel("请输入地址");
            m_dialog->show();
            break;
        }

        if(ui->lineEdit_temperature->text().toDouble() > 35.0 )
        {
            double temperature = ui->lineEdit_temperature->text().toDouble();
            if(m_settings)
            {
                m_settings->trySet("temperature",temperature);
            }
        }else {
                m_dialog = new Dialog(this);
                m_dialog->setLabel("请输入正确的体温");
                m_dialog->show();
                break;
        }

        QDBusMessage message =QDBusMessage::createMethodCall(
                                                             "com.qdbus.server",
                                                             "/com/qdbus/server",
                                                             "com.qdbus.server",
                                                             "server_get");
        message << ui->lineEdit_name->text()
                << ui->lineEdit_age->text().toInt()
                << ui->lineEdit_id->text()
                << ui->lineEdit_tel->text()
                << ui->lineEdit_adress->text()
                << ui->lineEdit_temperature->text().toDouble();

        QDBusConnection::sessionBus().call(message);

    }while(0);

}

void MainWindow::client_get_error()
{
    m_thermometer= new thermometer(this);
    m_thermometer->setLabel("体温异常,禁止通行");
    m_thermometer->setProgressBar(ui->lineEdit_temperature->text().toDouble());
    m_thermometer->show();

}


void MainWindow::client_get_ok()
{
    m_thermometer = new thermometer(this);
    m_thermometer->setLabel("体温正常,允许通行");
    m_thermometer->setProgressBar(ui->lineEdit_temperature->text().toDouble());
    m_thermometer->show();
}


