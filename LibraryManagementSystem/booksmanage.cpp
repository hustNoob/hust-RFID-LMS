#include "booksmanage.h"
#include "ui_booksmanage.h"
#include <QMessageBox>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QDate>
#include <QHeaderView>

BooksManage::BooksManage(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::BooksManage),
      sql(new Sqlite)
{
    ui->setupUi(this);

    // 设置输入验证
    ui->lineEdit_cardID->setValidator(new QRegExpValidator(QRegExp("[A-Fa-f0-9]*"), this));
    ui->lineEdit_goodsID->setValidator(new QRegExpValidator(QRegExp("[0-9]{10}"), this));
    ui->lineEdit_days->setValidator(new QRegExpValidator(QRegExp("[0-9]{3}"), this));

    // 表格设置
    ui->tableWidget_books->setColumnCount(9);
    QStringList headers;
    headers << tr("卡号") << tr("书籍ISBN号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("书籍类型") << tr("可借时间(天)") << tr("出版日期") << tr("是否借出");
    ui->tableWidget_books->setHorizontalHeaderLabels(headers);
    ui->tableWidget_books->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_books->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_books->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    // 连接信号槽
    connect(ui->pushButton_add,    SIGNAL(clicked()), this, SLOT(add_books()));
    connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(delete_books()));
    connect(ui->pushButton_update, SIGNAL(clicked()), this, SLOT(updata_books()));
    connect(ui->pushButton_search, SIGNAL(clicked()), this, SLOT(select_books()));
    connect(ui->tableWidget_books, SIGNAL(cellClicked(int,int)), this, SLOT(get_table_line(int,int)));

    ShowTable(sql->SelectBooks());
}

BooksManage::~BooksManage()
{
    delete ui;
    delete sql;
}

void BooksManage::add_books()
{
    QString LabelName[] = {tr("卡号"), tr("书籍编号"), tr("书名"), tr("作者"),
                           tr("出版社"), tr("图书类型"), tr("可借天数"), tr("出版时间")};
    QLineEdit* edits[] = {
        ui->lineEdit_cardID,
        ui->lineEdit_goodsID,
        ui->lineEdit_name,
        ui->lineEdit_author,
        ui->lineEdit_publisher,
        ui->lineEdit_type,
        ui->lineEdit_days
    };

    // 检查必填
    for(int i = 0; i < 7; ++i) {
        if(edits[i]->text().isEmpty()) {
            QMessageBox::warning(this, tr("警告"), LabelName[i] + tr("不能为空！"), QMessageBox::Yes);
            return;
        }
    }

    // 检查卡号是否为用户
    if (sql->SelectUser(ui->lineEdit_cardID->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为用户！"), QMessageBox::Yes);
        return;
    }

    // 插入数据库
    bool ret = sql->InsertBooks(
        ui->lineEdit_cardID->text(),
        ui->lineEdit_goodsID->text(),
        ui->lineEdit_name->text(),
        ui->lineEdit_author->text(),
        ui->lineEdit_publisher->text(),
        ui->lineEdit_type->text(),
        ui->lineEdit_days->text(),
        ui->dateEdit_publish->text()
    );
    if(!ret) {
        QMessageBox::warning(this, tr("警告"), tr("添加失败，卡号已存在！"), QMessageBox::Yes);
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("添加成功！"), QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectBooks());
}

void BooksManage::delete_books()
{
    QString cardId = ui->lineEdit_cardID->text();

    if (!cardId.isEmpty() && sql->SelectUser(cardId).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为用户！"), QMessageBox::Yes);
        return;
    }
    if (!cardId.isEmpty() && !sql->SelectBooks(cardId).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号不存在！"), QMessageBox::Yes);
        return;
    }

    sql->DeleteRecordBook(cardId);
    bool ret = sql->DeleteBooks(cardId);
    if(!ret) {
        QMessageBox::warning(this, tr("警告"), tr("删除失败！"), QMessageBox::Yes);
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("删除成功！"), QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectBooks());
}

void BooksManage::updata_books()
{
    QString cardId = ui->lineEdit_cardID->text();

    if (!cardId.isEmpty() && sql->SelectUser(cardId).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为用户！"), QMessageBox::Yes);
        return;
    }
    if (!cardId.isEmpty() && !sql->SelectBooks(cardId).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号不存在！"), QMessageBox::Yes);
        return;
    }

    bool ret = sql->UpdataBooks(
        ui->lineEdit_cardID->text(),
        ui->lineEdit_goodsID->text(),
        ui->lineEdit_name->text(),
        ui->lineEdit_author->text(),
        ui->lineEdit_publisher->text(),
        ui->lineEdit_type->text(),
        ui->dateEdit_publish->text(),
        ui->lineEdit_days->text()
    );
    if(!ret) {
        QMessageBox::warning(this, tr("警告"), tr("修改失败！"), QMessageBox::Yes);
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("修改成功！"), QMessageBox::Yes);
    ClearEdit();
    ShowTable(sql->SelectBooks());
}

void BooksManage::select_books()
{
    QSqlQuery query = sql->SelectBooks(
        ui->lineEdit_cardID->text(),
        ui->lineEdit_name->text(),
        ui->lineEdit_author->text(),
        ui->lineEdit_publisher->text(),
        ui->lineEdit_type->text()
    );
    ShowTable(query);
    ClearEdit();
}

void BooksManage::ShowTable(QSqlQuery query)
{
    QStringList headers;
    headers << tr("卡号") << tr("书籍ISBN号") << tr("书名") << tr("作者")
            << tr("出版社") << tr("书籍类型") << tr("可借时间(天)") << tr("出版日期") << tr("是否借出");
    ui->tableWidget_books->setHorizontalHeaderLabels(headers);

    if (!query.next()) {
        ui->tableWidget_books->setRowCount(0);
        return;
    }
    // 统计行数
    query.last();
    int nRows = query.at() + 1;
    ui->tableWidget_books->setRowCount(nRows);
    int row = 0;
    query.first();
    do {
        for (int col = 0; col < ui->tableWidget_books->columnCount(); ++col) {
            ui->tableWidget_books->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    } while(query.next());
}

void BooksManage::ClearEdit()
{
    ui->lineEdit_cardID->clear();
    ui->lineEdit_goodsID->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_author->clear();
    ui->lineEdit_publisher->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_days->clear();
    ui->dateEdit_publish->setDate(QDate::currentDate());
}

void BooksManage::get_table_line(int row, int /*col*/)
{
    ui->lineEdit_cardID->setText(ui->tableWidget_books->item(row, 0)->text());
    ui->lineEdit_goodsID->setText(ui->tableWidget_books->item(row, 1)->text());
    ui->lineEdit_name->setText(ui->tableWidget_books->item(row, 2)->text());
    ui->lineEdit_author->setText(ui->tableWidget_books->item(row, 3)->text());
    ui->lineEdit_publisher->setText(ui->tableWidget_books->item(row, 4)->text());
    ui->lineEdit_type->setText(ui->tableWidget_books->item(row, 5)->text());
    ui->lineEdit_days->setText(ui->tableWidget_books->item(row, 6)->text());
    ui->dateEdit_publish->setDate(
        QDate::fromString(ui->tableWidget_books->item(row, 7)->text(), "yyyy-MM-dd"));
}

void BooksManage::SetCard(const QString& cardID)
{
    ui->lineEdit_cardID->setText(cardID);
}

void BooksManage::Clear()
{
    ClearEdit();
    ShowTable(sql->SelectBooks());
}
