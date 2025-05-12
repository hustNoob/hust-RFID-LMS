#include "usermanage.h"
#include "ui_usermanage.h"
#include <QRegExpValidator>
#include <QHeaderView>
#include <QMessageBox>

UserManage::UserManage(QWidget *parent)
    : QWidget(parent), ui(new Ui::UserManage), sql(new Sqlite)
{
    ui->setupUi(this);

    // 输入校验
    QRegExp regExp("[A-Fa-f0-9]*");
    ui->lineEdit_cardid->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[\u4e00-\u9fa5]*");
    ui->lineEdit_name->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[男女]");
    ui->lineEdit_gender->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[0-9]{2}");
    ui->lineEdit_age->setValidator(new QRegExpValidator(regExp, this));

    regExp.setPattern("[0-9]{11}");
    ui->lineEdit_tel->setValidator(new QRegExpValidator(regExp, this));

    // 表格设置
    ui->tableWidget_user->setColumnCount(6);
    QStringList headers;
    headers << tr("卡号") << tr("姓名") << tr("性别") << tr("年龄") << tr("手机号") << tr("是否挂失");
    ui->tableWidget_user->setHorizontalHeaderLabels(headers);
    ui->tableWidget_user->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_user->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_user->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 信号槽连接
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(add_user()));
    connect(ui->pushButton_delete, SIGNAL(clicked()), this, SLOT(delete_user()));
    connect(ui->pushButton_update, SIGNAL(clicked()), this, SLOT(updata_user()));
    connect(ui->pushButton_search, SIGNAL(clicked()), this, SLOT(select_user()));
    connect(ui->pushButton_lost, SIGNAL(clicked()), this, SLOT(clickedLostUser()));
    connect(ui->pushButton_find, SIGNAL(clicked()), this, SLOT(clickedFindUser()));
    connect(ui->pushButton_logout, SIGNAL(clicked()), this, SLOT(clickedLogoutUser()));
    connect(ui->tableWidget_user, SIGNAL(cellClicked(int,int)), this, SLOT(get_table_line(int,int)));

    ShowTable(sql->SelectUser());
}

UserManage::~UserManage()
{
    delete ui;
    delete sql;
}

// 添加用户
void UserManage::add_user()
{
    QLineEdit* edit[] = {ui->lineEdit_cardid, ui->lineEdit_name, ui->lineEdit_gender, ui->lineEdit_age, ui->lineEdit_tel};
    QString labelName[] = {tr("卡号："), tr("姓名："), tr("性别："), tr("年龄："), tr("手机号：")};

    for (int i = 0; i < 5; ++i) {
        if (edit[i]->text().isEmpty()) {
            QMessageBox::warning(this, tr("警告"), labelName[i] + tr("不能为空！"));
            return;
        }
    }

    if (sql->SelectBooks(ui->lineEdit_cardid->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为书籍！"));
        return;
    }
    int ret = sql->InsertUser(
        ui->lineEdit_cardid->text(),
        ui->lineEdit_name->text(),
        ui->lineEdit_gender->text(),
        ui->lineEdit_age->text().toInt(),
        ui->lineEdit_tel->text()
    );

    if(!ret) {
        QMessageBox::warning(this, tr("警告"), tr("添加失败，编号已存在！"));
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("添加成功！"));
    ClearEdit();
    ShowTable(sql->SelectUser());
}

// 删除用户
void UserManage::delete_user()
{
    if (!ui->lineEdit_cardid->text().isEmpty() && sql->SelectBooks(ui->lineEdit_cardid->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为书籍！"));
        return;
    }
    if (!ui->lineEdit_cardid->text().isEmpty() && !sql->SelectUser(ui->lineEdit_cardid->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号不存在！"));
        return;
    }
    int Age = ui->lineEdit_age->text().isEmpty() ? -1 : ui->lineEdit_age->text().toInt();

    int result = QMessageBox::warning(this, tr("警告"), tr("是否要将用户注销？"), QMessageBox::Ok | QMessageBox::Cancel);
    if(result == QMessageBox::Ok)
    {
        sql->DeleteRecordUser(ui->lineEdit_cardid->text());
        int ret = sql->DeleteUser(ui->lineEdit_cardid->text(), ui->lineEdit_name->text(), ui->lineEdit_gender->text(), Age);
        if(!ret) {
            QMessageBox::warning(this, tr("警告"), tr("删除失败！"));
            return;
        }
        QMessageBox::information(this, tr("提示"), tr("删除成功！"));
    }
    ClearEdit();
    ShowTable(sql->SelectUser());
}

// 修改用户
void UserManage::updata_user()
{
    if (!ui->lineEdit_cardid->text().isEmpty() && sql->SelectBooks(ui->lineEdit_cardid->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号已经注册为书籍！"));
        return;
    }
    if (!ui->lineEdit_cardid->text().isEmpty() && !sql->SelectUser(ui->lineEdit_cardid->text()).next()) {
        QMessageBox::warning(this, tr("警告"), tr("卡号不存在！"));
        return;
    }
    int ret = sql->UpdataUser(
        ui->lineEdit_cardid->text(),
        ui->lineEdit_name->text(),
        ui->lineEdit_gender->text(),
        ui->lineEdit_age->text().toInt(),
        ui->lineEdit_tel->text()
    );
    if(!ret) {
        QMessageBox::warning(this, tr("警告"), tr("修改失败！"));
        return;
    }
    QMessageBox::information(this, tr("提示"), tr("修改成功！"));
    ClearEdit();
    ShowTable(sql->SelectUser());
}

// 搜索用户
void UserManage::select_user()
{
    QSqlQuery query;
    if(ui->lineEdit_age->text().isEmpty())
        query = sql->SelectUser(ui->lineEdit_cardid->text(), ui->lineEdit_name->text(),
                                ui->lineEdit_gender->text(), -1, ui->lineEdit_tel->text());
    else
        query = sql->SelectUser(ui->lineEdit_cardid->text(), ui->lineEdit_name->text(),
                                ui->lineEdit_gender->text(), ui->lineEdit_age->text().toInt(),
                                ui->lineEdit_tel->text());
    ShowTable(query);
}

// 表格显示
void UserManage::ShowTable(QSqlQuery query)
{
    QStringList headers;
    headers << tr("卡号") << tr("姓名") << tr("性别") << tr("年龄") << tr("手机号") << tr("是否挂失");
    ui->tableWidget_user->setHorizontalHeaderLabels(headers);

    if(!query.next())
    {
        ui->tableWidget_user->setRowCount(0);
        return;
    }
    query.last();
    int nRow = query.at() + 1;
    ui->tableWidget_user->setRowCount(nRow);
    int row = 0;
    query.first();
    do
    {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget_user->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    } while(query.next());
}

// 表格单击显示到输入框
void UserManage::get_table_line(int row, int)
{
    ui->lineEdit_cardid->setText(ui->tableWidget_user->item(row,0)->text());
    ui->lineEdit_name->setText(ui->tableWidget_user->item(row,1)->text());
    ui->lineEdit_gender->setText(ui->tableWidget_user->item(row,2)->text());
    ui->lineEdit_age->setText(ui->tableWidget_user->item(row,3)->text());
    ui->lineEdit_tel->setText(ui->tableWidget_user->item(row,4)->text());
    isLast = ui->tableWidget_user->item(row,5)->text();
}

// 挂失
void UserManage::clickedLostUser()
{
    if(ui->lineEdit_cardid->text().isEmpty())
    {
        QMessageBox::warning(this, tr("错误"), tr("没有卡片或没有选中数据"));
        return;
    }
    if(isLast == "true")
    {
        QMessageBox::warning(this, tr("错误"), tr("该账户已经被挂失！"));
    }
    else {
        if(sql->Updata("user_15693","isLocked = 'true'", "cardID = '"+ui->lineEdit_cardid->text()+"'"))
            QMessageBox::information(this, tr("提示"), tr("账户挂失成功！"));
        else
            QMessageBox::warning(this, tr("错误"), tr("账户挂失失败"));
    }
    Clear();
}

// 取消挂失
void UserManage::clickedFindUser()
{
    if(ui->lineEdit_cardid->text().isEmpty())
    {
        QMessageBox::warning(this, tr("错误"), tr("没有卡片或没有选中数据"));
        return;
    }
    if(isLast == "false")
    {
        QMessageBox::warning(this, tr("错误"), tr("该账户没有被挂失！"));
    }
    else {
        if(sql->Updata("user_15693","isLocked = 'false'", "cardID = '"+ui->lineEdit_cardid->text()+"'"))
            QMessageBox::information(this, tr("提示"), tr("账户取消挂失成功！"));
        else
            QMessageBox::warning(this, tr("错误"), tr("账户取消挂失失败"));
    }
    Clear();
}

// 注销用户(示例，仅弹出警告)
void UserManage::clickedLogoutUser()
{
    if(ui->lineEdit_cardid->text().isEmpty())
    {
        QMessageBox::warning(this, tr("错误"), tr("没有卡片或没有选中数据"));
        return;
    }
    QMessageBox::warning(this, tr("警告"), tr("不能为空！"));
}

// 设置卡号
void UserManage::SetCard(const QString &cardID)
{
    ui->lineEdit_cardid->setText(cardID);
}

// 清空文本框
void UserManage::ClearEdit()
{
    ui->lineEdit_cardid->clear();
    ui->lineEdit_name->clear();
    ui->lineEdit_gender->clear();
    ui->lineEdit_age->clear();
    ui->lineEdit_tel->clear();
}

// 清空并刷表
void UserManage::Clear()
{
    ClearEdit();
    ShowTable(sql->SelectUser());
}
