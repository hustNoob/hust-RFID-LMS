#ifndef RECORD_H
#define RECORD_H

#include <QWidget>
#include <QSqlQuery>
#include "sqlite.h"

namespace Ui {
class Record;
}

class Record : public QWidget
{
    Q_OBJECT
public:
    explicit Record(QWidget *parent = 0);
    ~Record();

    void ShowTable(QSqlQuery query);
    void Clear();
    void ClearEdit();
    void SetCard(const QString &cardID);

public slots:
    void delete_record();
    void select_record();
    void get_table_line(int row, int col);

private:
    Ui::Record *ui;
    Sqlite *sql;
    int select_row;
};

#endif // RECORD_H
