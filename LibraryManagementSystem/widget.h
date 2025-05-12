#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "borrow_return.h"
#include "usermanage.h"
#include "booksmanage.h"
#include "record.h"
#include "sqlite.h"
#include "uhf_thread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void getSerialName(QStringList *list);

public slots:
    void Uhf_Connect_Button_Click();
    void Uhf_Disconnect_Button_Click();
    void Get_Info(QByteArray Info);
    void Get_User_Info();
    void RefreshWidget(int index);

private:
    Ui::Widget *ui;
    Borrow_Return *borrow_return;
    Record *record;
    UserManage *user_manage;
    BooksManage *books_manage;
    Sqlite *sql;
    UHF_Thread *uhf;
};

#endif // WIDGET_H
