#ifndef BORROW_RETURN_H
#define BORROW_RETURN_H

#include <QWidget>
#include <QDateTime>
#include <QSqlQuery>
#include "sqlite.h"

namespace Ui {
class Borrow_Return;
}

class Borrow_Return : public QWidget
{
    Q_OBJECT
public:
    explicit Borrow_Return(QWidget *parent = 0);
    ~Borrow_Return();

    void ShowTable(QSqlQuery query); //显示表格
    void SetInfo(const QString& cardID); //获取卡号
    void Clear(); //清空文本框和表格信息
    static int GetHowManyDays(QDateTime start, QDateTime end);

    const QString FORMAT = "yyyy-MM-dd hh:mm:ss";

private:
    Ui::Borrow_Return* ui;
    Sqlite* sql;
};

#endif // BORROW_RETURN_H
