#ifndef BOOKSMANAGE_H
#define BOOKSMANAGE_H

#include <QWidget>
#include <QSqlQuery>
#include "sqlite.h"

// 向前声明自动生成的ui类
namespace Ui {
class BooksManage;
}

class BooksManage : public QWidget
{
    Q_OBJECT

public:
    explicit BooksManage(QWidget *parent = 0);
    ~BooksManage();

    void ShowTable(QSqlQuery query);
    void ClearEdit();
    void Clear();
    void SetCard(const QString &cardID);

public slots:
    void add_books();
    void delete_books();
    void updata_books();
    void select_books();
    void get_table_line(int row, int col);

private:
    Ui::BooksManage *ui;
    Sqlite *sql;
};

#endif // BOOKSMANAGE_H
