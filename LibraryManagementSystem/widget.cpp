#include "widget.h"
#include "ui_widget.h"
#include "inc/m1356dll.h"
#include <QFile>
#include <QPixmap>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget),
      borrow_return(0),
      record(0),
      user_manage(0),
      books_manage(0),
      sql(0),
      uhf(0)
{
    ui->setupUi(this);

    // 顶部图片
    QPixmap jpg(":/img/img/hust.webp");
    jpg = jpg.scaled(70,70, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label_picture->setPixmap(jpg);

    // 串口相关
    ui->comboBox_baud->addItems(QStringList()
        << "110" << "300" << "1200" << "2400" << "4800" << "9600" << "19200" << "38400"
        << "57600" << "115200" << "230400" << "460800" << "921600");
    QStringList serial;
    getSerialName(&serial);
    ui->comboBox_serial->addItems(serial);
    ui->comboBox_baud->setCurrentIndex(6);

    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_disconnect->setDisabled(true);

    // 子页面
    borrow_return = new Borrow_Return();
    record = new Record();
    user_manage = new UserManage();
    books_manage = new BooksManage();
    ui->tabWidget_main->addTab(borrow_return, tr("借/还书"));
    ui->tabWidget_main->addTab(record, tr("借书列表"));
    ui->tabWidget_main->addTab(user_manage, tr("用户管理"));
    ui->tabWidget_main->addTab(books_manage, tr("图书管理"));
    ui->tabWidget_main->setDisabled(true); // 默认未连接不可用

    // 数据库
    sql = new Sqlite();
    sql->Connect();

    // 读卡线程
    uhf = new UHF_Thread();

    // 连接信号槽
    connect(ui->pushButton_connect, SIGNAL(clicked()), this, SLOT(Uhf_Connect_Button_Click()));
    connect(ui->pushButton_disconnect, SIGNAL(clicked()), this, SLOT(Uhf_Disconnect_Button_Click()));
    connect(uhf, SIGNAL(receivedMsg(QByteArray)), this, SLOT(Get_Info(QByteArray)), Qt::BlockingQueuedConnection);
    connect(uhf, SIGNAL(cycle()), this, SLOT(Get_User_Info()), Qt::BlockingQueuedConnection);
    connect(ui->tabWidget_main, SIGNAL(currentChanged(int)), this, SLOT(RefreshWidget(int)));
}

Widget::~Widget()
{
    delete ui;
    delete borrow_return;
    delete record;
    delete user_manage;
    delete books_manage;
    delete sql;
    delete uhf;
}

void Widget::getSerialName(QStringList *list)
{
    QStringList temp;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite)) {
            if (!list->contains(info.portName(), Qt::CaseSensitive))
                list->insert(0, info.portName());
            serial.close();
            temp << info.portName();
        }
    }
    for (int i = 0; i < list->size(); i++) {
        if (!temp.contains(list->at(i)))
            list->removeAt(i--);
    }
}

void Widget::Uhf_Connect_Button_Click()
{
    uhf->nRunFlag = true;
    uhf->UART_Connect(ui->comboBox_serial->currentText(), ui->comboBox_baud->currentText().toInt());
    uhf->start();
    uhf->InitUhf();
    ui->tabWidget_main->setEnabled(true);
    ui->pushButton_disconnect->setEnabled(true);
    ui->pushButton_connect->setDisabled(true);
}

void Widget::Uhf_Disconnect_Button_Click()
{
    uhf->nRunFlag = false;
    uhf->UART_Disconnect();
    ui->tabWidget_main->setDisabled(true);
    ui->pushButton_connect->setEnabled(true);
    ui->pushButton_disconnect->setDisabled(true);
}

void Widget::Get_Info(QByteArray Info)
{
    M1356Dll Dll;
    M1356_RspFrame_t data = Dll.M1356_RspFrameConstructor(Info);
    if (Dll.RC632_AnalysisFrame((uint8*)(Info.data()), RC632_CMD_ISO15693_INVENTORY16) != 0xff) {
        if (Dll.RC632_UartCalcFCS(((uint8*)(Info.data()+4)), BUILD_UINT8(Info.at(3), Info.at(2))-1)) {
            QString cardID = data.vdata.replace(" ","");
            switch (ui->tabWidget_main->currentIndex()) {
                case 0:
                    borrow_return->SetInfo(cardID);
                    break;
                case 1:
                    record->SetCard(cardID);
                    break;
                case 2:
                    user_manage->SetCard(cardID);
                    break;
                case 3:
                    books_manage->SetCard(cardID);
                    break;
                default:
                    break;
            }
        }
    }
}

void Widget::Get_User_Info()
{
    uhf->ReadCardID();
}

void Widget::RefreshWidget(int index)
{
    switch(index)
    {
    case 0:
        borrow_return->Clear();
        break;
    case 1:
        record->Clear();
        break;
    case 2:
        user_manage->Clear();
        break;
    case 3:
        books_manage->Clear();
        break;
    }
}
