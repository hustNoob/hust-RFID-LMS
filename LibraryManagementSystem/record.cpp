#include "record.h"
#include "ui_record.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QHeaderView>

Record::Record(QWidget *parent)
    : QWidget(parent), ui(new Ui::Record), sql(new Sqlite), select_row(-1)
{
    ui->setupUi(this);

    // 设置表格列数
    ui->tableWidget_record->setColumnCount(11);
    QStringList headers;
    headers << tr("记录编号") << tr("是否在借") << tr("用户卡号")
            << tr("用户姓名") << tr("手机号")
            << tr("书籍卡号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("借书时间") << tr("还书时间");
    ui->tableWidget_record->setHorizontalHeaderLabels(headers);

    ui->tableWidget_record->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_record->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(9, QHeaderView::ResizeToContents);
    ui->tableWidget_record->horizontalHeader()->setSectionResizeMode(10, QHeaderView::ResizeToContents);

    // 输入校验
    QRegExp regExp("[A-Fa-f0-9]*");
    ui->lineEdit_userid->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_bookid->setValidator(new QRegExpValidator(regExp, this));

    // 连接信号槽
    connect(ui->pushButton_select, SIGNAL(clicked()), this, SLOT(select_record()));
    connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(delete_record()));
    connect(ui->tableWidget_record, SIGNAL(cellClicked(int,int)), this, SLOT(get_table_line(int,int)));

    ui->label_status->setText(tr("可通过刷卡搜索查看某本书或某个用户的记录"));

    ShowTable(sql->SelectRecord());
}

Record::~Record()
{
    delete ui;
    delete sql;
}

void Record::ShowTable(QSqlQuery query)
{
    QStringList headers;
    headers << tr("记录编号") << tr("是否在借") << tr("用户卡号")
            << tr("用户姓名") << tr("手机号")
            << tr("书籍卡号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("借书时间") << tr("还书时间");
    ui->tableWidget_record->setHorizontalHeaderLabels(headers);

    if(!query.next())
    {
        ui->tableWidget_record->setRowCount(0);
        return;
    }

    query.last();
    int nRow = query.at() + 1;
    ui->tableWidget_record->setRowCount(nRow);
    int row = 0;

    query.first();
    do
    {
        for(int col = 0; col < ui->tableWidget_record->columnCount(); col++)
        {
            ui->tableWidget_record->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    }while(query.next());
}

void Record::select_record()
{
    QSqlQuery query = sql->SelectRecord(ui->lineEdit_userid->text(), ui->lineEdit_bookid->text());
    ShowTable(query);
    ClearEdit();
}

void Record::delete_record()
{
    // 只有选中行才可删
    if (select_row < 0) return;
    QString id = ui->tableWidget_record->item(select_row, 0)->text();
    bool ret = sql->DeleteRecord(id);
    if(!ret)
    {
        QMessageBox::warning(this, tr("警告"), tr("删除失败！"), QMessageBox::Yes);
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("删除成功！"), QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectRecord());
    select_row = -1;
}

void Record::ClearEdit()
{
    ui->lineEdit_userid->clear();
    ui->lineEdit_bookid->clear();
}

void Record::get_table_line(int row, int /*col*/)
{
    ui->lineEdit_userid->setText(ui->tableWidget_record->item(row,2)->text());
    ui->lineEdit_bookid->setText(ui->tableWidget_record->item(row,5)->text());
    select_row = row;
}

void Record::Clear()
{
    ShowTable(sql->SelectRecord());
}

void Record::SetCard(const QString &cardID)
{
    QSqlQuery query = sql->SelectUser(cardID);
    if(query.next())
    {
        ui->lineEdit_userid->setText(cardID);
        return;
    }
    query = sql->SelectBooks(cardID);
    if(query.next())
    {
        ui->lineEdit_bookid->setText(cardID);
        return;
    }
    QMessageBox::information(this, tr("提示！"), tr("该卡没有在系统中注册！"),
                              QMessageBox::Ok, QMessageBox::NoButton);
}
