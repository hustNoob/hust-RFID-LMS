#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>
#include <QSqlQuery>
#include "sqlite.h"

namespace Ui {
class UserManage;
}

class UserManage : public QWidget
{
    Q_OBJECT
public:
    explicit UserManage(QWidget *parent = 0);
    ~UserManage();

    void ShowTable(QSqlQuery query);
    void ClearEdit();
    void Clear();
    void SetCard(const QString &cardID);

public slots:
    void add_user();
    void delete_user();
    void updata_user();
    void select_user();
    void get_table_line(int row, int col);
    void clickedLostUser();
    void clickedFindUser();
    void clickedLogoutUser();

private:
    Ui::UserManage *ui;
    Sqlite *sql;
    QString isLast; //是否挂失
};

#endif // USERMANAGE_H
