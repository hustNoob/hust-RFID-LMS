#include "borrow_return.h"
#include "ui_borrow_return.h"
#include <QMessageBox>
#include <QButtonGroup>
#include <QDateTime>
#include <QHeaderView>

Borrow_Return::Borrow_Return(QWidget *parent)
    : QWidget(parent), ui(new Ui::Borrow_Return), sql(new Sqlite)
{
    ui->setupUi(this);

    // 默认借书单选选中
    ui->radioButton_borrow->setChecked(true);

    // 表格设置
    ui->tableWidget_books->setColumnCount(8);
    QStringList headers;
    headers << tr("是否在借") << tr("图书卡号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("借书时间") << tr("还书时间") << tr("已借时间");
    ui->tableWidget_books->setHorizontalHeaderLabels(headers);
    ui->tableWidget_books->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_books->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);

    // 按钮分组（代码）
    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->radioButton_borrow);
    group->addButton(ui->radioButton_return);

    // 初始化界面状态
    Clear();
}

Borrow_Return::~Borrow_Return()
{
    delete ui;
    delete sql;
}

void Borrow_Return::ShowTable(QSqlQuery query)
{
    QStringList headers;
    headers << tr("是否在借") << tr("图书卡号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("借书时间") << tr("还书时间") << tr("已借时间");
    ui->tableWidget_books->setHorizontalHeaderLabels(headers);

    if(!query.next())
    {
        ui->tableWidget_books->setRowCount(0);
        return;
    }

    query.last();
    int nRow = query.at() + 1;
    ui->tableWidget_books->setRowCount(nRow);
    int row = 0;
    query.first();

    QString username = query.value(3).toString();
    QDateTime lendtime, returntime;
    QString days;
    QString renting = tr("当前借书列表：\n");
    int count_rent = 0, overtime_count = 0;

    do
    {
        lendtime  = QDateTime::fromString(query.value(9).toString(), FORMAT);
        // 看是否已还
        if(query.value(1) == tr("否"))
        {
            returntime = QDateTime::fromString(query.value(10).toString(), FORMAT);
            days = QString::asprintf("%-3d天(已完成)", GetHowManyDays(lendtime, returntime));
        }
        else {
            count_rent++;
            returntime = QDateTime::currentDateTime();
            int day = GetHowManyDays(lendtime, returntime);
            // 超时
            if(day > query.value(11).toInt())
            {
                overtime_count++;
                days = QString::asprintf("%-3d天(已超时)", day);
                renting += ( query.value(6).toString() + tr("  已超时！超时 ") +
                             QString::number(day - query.value(11).toInt()) + tr(" 天\n"));
            }
            else {
                days = QString::asprintf("%-3d天(正在借)", day);
                renting += ( "《" + query.value(6).toString() + "》  " + tr("还剩") +
                            QString::number(query.value(11).toInt() - day)+ tr(" 天\n"));
            }
        }
        //填表格
        ui->tableWidget_books->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget_books->setItem(row, 1, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget_books->setItem(row, 2, new QTableWidgetItem(query.value(6).toString()));
        ui->tableWidget_books->setItem(row, 3, new QTableWidgetItem(query.value(7).toString()));
        ui->tableWidget_books->setItem(row, 4, new QTableWidgetItem(query.value(8).toString()));
        ui->tableWidget_books->setItem(row, 5, new QTableWidgetItem(query.value(9).toString()));
        ui->tableWidget_books->setItem(row, 6, new QTableWidgetItem(query.value(10).toString()));
        ui->tableWidget_books->setItem(row, 7, new QTableWidgetItem(days));
        row++;
    } while(query.next());

    QString Infoma = QString::asprintf("请先放人物卡再放图书卡：%s\n当前借书：%-2d本\n当前已超时:%-2d本\n\n", username.toStdString().c_str(), count_rent, overtime_count );
    if(count_rent) {
        Infoma += renting;
    }
    ui->label_info->setText(Infoma);
}

void Borrow_Return::SetInfo(const QString& cardID)
{
    // 用户信息
    QSqlQuery query = sql->SelectUser(cardID);
    if (query.next())
    {
        // 判断是否未激活
        if (query.value(5).toString() == "true")
        {
            QMessageBox::warning(this, tr("警告！"), tr("该用户未激活！\n该卡无法使用！！"), QMessageBox::Ok, QMessageBox::NoButton);
            ui->label_status->setText(tr("登陆失败！   该卡未激活！"));
            return;
        }
        ui->lineEdit_cardid->setText(query.value(0).toString());
        ui->lineEdit_name->setText(query.value(1).toString());
        ui->lineEdit_gender->setText(query.value(2).toString());
        ui->lineEdit_age->setText(query.value(3).toString());
        ui->lineEdit_tel->setText(query.value(4).toString());
        ShowTable(sql->SelectRecord(cardID));
        ui->tableWidget_books->setEnabled(true);
        ui->label_status->setText(tr("登录成功！   请刷书籍卡借书或还书。"));
        return;
    }

    // 如果是书
    query = sql->SelectBooks(cardID);
    if(query.next())
    {
        // 如果未登录
        if(ui->lineEdit_cardid->text().isEmpty())
        {
            ui->label_status->setText(tr("该卡是书！  请先刷用户卡登陆！"));
            return;
        }
        // 借书
        if(ui->radioButton_borrow->isChecked())
        {
            if(sql->SelectRecord(ui->lineEdit_cardid->text(), query.value(0).toString(), true).next())
            {
                QMessageBox::information(this, tr("提示！"), tr("该书籍已经被您借出\n若需要归还请点击还书按钮！！"),
                                         QMessageBox::Ok, QMessageBox::NoButton);
                return;
            }
            if(query.value(8).toString() == tr("是"))
            {
                QMessageBox::information(this, tr("提示！"), tr("该书籍已经被其他人借出\n借书失败！"),
                                         QMessageBox::Ok, QMessageBox::NoButton);
                return;
            }
            // 借书确认弹窗
            QMessageBox msgBox;
            QString bookinfo = tr("书名   ：  ") + query.value(2).toString() + "\n" +
                               tr("作者   ：  ") + query.value(3).toString() + "\n" +
                               tr("出版社 ：  ") + query.value(4).toString() + "\n" +
                               tr("可借天数：  ") + query.value(6).toString() + tr(" 天\n")
                               + tr("请在到期前归还！\n\n是否借出？");
            int ret = msgBox.question(this, tr("借书"), bookinfo, QMessageBox::Ok, QMessageBox::Cancel);
            if (ret == QMessageBox::Ok)
            {
                if(!sql->InsertRecord(query.value(0).toString(), ui->lineEdit_cardid->text(),
                                      QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")))
                    QMessageBox::critical(this, tr("错误！"), tr("数据库操作错误！"), QMessageBox::Ok, QMessageBox::NoButton);
                if(!sql->UpdataBooks(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                     query.value(4).toString(),query.value(5).toString(),query.value(6).toString(), query.value(7).toString(), tr("是")))
                    QMessageBox::critical(this, tr("错误！"), tr("数据库操作错误！"), QMessageBox::Ok, QMessageBox::NoButton);
            }
        }
        // 还书
        else
        {
            QSqlQuery record_query = sql->SelectRecord(ui->lineEdit_cardid->text(), query.value(0).toString(), true);
            if(!record_query.next())
            {
                QMessageBox::information(this, tr("提示！"), tr("该书没有被您借出！\n还书失败！"),
                                         QMessageBox::Ok, QMessageBox::NoButton);
                return;
            }
            QDateTime lendtime = QDateTime::fromString(record_query.value(9).toString(), "yyyy-MM-dd hh:mm:ss");
            QDateTime currenttime = QDateTime::currentDateTime();

            QMessageBox msgBox;
            QString return_info = tr("书名   ：  ") + query.value(2).toString()+"\n"+
                                  tr("作者   ：  ") + query.value(3).toString()+"\n"+
                                  tr("出版社 ：  ") + query.value(4).toString()+"\n"+
                                  tr("可借天数：  ") + query.value(6).toString()+" 天\n\n"+
                                  tr("借书时间：  ") + record_query.value(9).toString()+"\n"+
                                  tr("已借时间：  ") + QString::number(GetHowManyDays(lendtime, currenttime)) + tr(" 天\n");
            if(GetHowManyDays(lendtime, currenttime) > query.value(11).toInt())
                return_info += tr("状态     ：  已超时! \n\n");
            else
                return_info += tr("状态     ：  未超时 \n\n");
            return_info += tr("请确认是否还书？");
            int ret = msgBox.question(this, tr("还书"), return_info, QMessageBox::Ok, QMessageBox::Cancel);

            if(ret == QMessageBox::Ok)
            {
                if(!sql->UpdateRecord(record_query.value(0).toInt(), currenttime.toString("yyyy-MM-dd hh:mm:ss")))
                    QMessageBox::critical(this, tr("错误！"), tr("数据库操作错误！"), QMessageBox::Ok, QMessageBox::NoButton);

                if(!sql->UpdataBooks(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),
                                     query.value(4).toString(),query.value(5).toString(),query.value(6).toString(), query.value(7).toString(), tr("否")))
                    QMessageBox::critical(this, tr("错误！"), tr("数据库操作错误！"), QMessageBox::Ok, QMessageBox::NoButton);
            }
        }
        ShowTable(sql->SelectRecord(ui->lineEdit_cardid->text()));
        return;
    }
    ui->label_status->setText(tr("该卡没有在本系统中注册！"));
}

void Borrow_Return::Clear()
{
    ui->lineEdit_cardid->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_gender->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_tel->clear();

    QSqlQuery empty;
    if(ui->lineEdit_cardid->text().isEmpty())
        ShowTable(empty);
    else
        ShowTable(sql->SelectRecord(ui->lineEdit_cardid->text()));
    ui->tableWidget_books->setDisabled(true);
    ui->label_status->setText(tr("请先刷卡登录！"));
    ui->label_info->setText(tr("欢迎："));
}

int Borrow_Return::GetHowManyDays(QDateTime start, QDateTime end)
{
    const int ndaysec = 24*60*60;
    uint stime = start.toTime_t();
    uint etime = end.toTime_t();
    return (etime - stime)/(ndaysec);
}
