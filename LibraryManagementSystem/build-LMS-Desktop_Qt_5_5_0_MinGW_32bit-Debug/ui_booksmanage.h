/********************************************************************************
** Form generated from reading UI file 'booksmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSMANAGE_H
#define UI_BOOKSMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BooksManage
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_info;
    QHBoxLayout *horizontalLayout_info;
    QGridLayout *gridLayout_form;
    QLabel *label_cardID;
    QLineEdit *lineEdit_cardID;
    QLabel *label_goodsID;
    QLineEdit *lineEdit_goodsID;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_author;
    QLineEdit *lineEdit_author;
    QLabel *label_publisher;
    QLineEdit *lineEdit_publisher;
    QLabel *label_type;
    QLineEdit *lineEdit_type;
    QLabel *label_days;
    QLineEdit *lineEdit_days;
    QLabel *label_publish_date;
    QDateEdit *dateEdit_publish;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_update;
    QPushButton *pushButton_search;
    QGroupBox *groupBox_table;
    QVBoxLayout *verticalLayout_table;
    QTableWidget *tableWidget_books;

    void setupUi(QWidget *BooksManage)
    {
        if (BooksManage->objectName().isEmpty())
            BooksManage->setObjectName(QStringLiteral("BooksManage"));
        verticalLayout = new QVBoxLayout(BooksManage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_info = new QGroupBox(BooksManage);
        groupBox_info->setObjectName(QStringLiteral("groupBox_info"));
        horizontalLayout_info = new QHBoxLayout(groupBox_info);
        horizontalLayout_info->setObjectName(QStringLiteral("horizontalLayout_info"));
        gridLayout_form = new QGridLayout();
        gridLayout_form->setObjectName(QStringLiteral("gridLayout_form"));
        label_cardID = new QLabel(groupBox_info);
        label_cardID->setObjectName(QStringLiteral("label_cardID"));

        gridLayout_form->addWidget(label_cardID, 0, 0, 1, 1);

        lineEdit_cardID = new QLineEdit(groupBox_info);
        lineEdit_cardID->setObjectName(QStringLiteral("lineEdit_cardID"));

        gridLayout_form->addWidget(lineEdit_cardID, 0, 1, 1, 1);

        label_goodsID = new QLabel(groupBox_info);
        label_goodsID->setObjectName(QStringLiteral("label_goodsID"));

        gridLayout_form->addWidget(label_goodsID, 0, 2, 1, 1);

        lineEdit_goodsID = new QLineEdit(groupBox_info);
        lineEdit_goodsID->setObjectName(QStringLiteral("lineEdit_goodsID"));

        gridLayout_form->addWidget(lineEdit_goodsID, 0, 3, 1, 1);

        label_name = new QLabel(groupBox_info);
        label_name->setObjectName(QStringLiteral("label_name"));

        gridLayout_form->addWidget(label_name, 1, 0, 1, 1);

        lineEdit_name = new QLineEdit(groupBox_info);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout_form->addWidget(lineEdit_name, 1, 1, 1, 1);

        label_author = new QLabel(groupBox_info);
        label_author->setObjectName(QStringLiteral("label_author"));

        gridLayout_form->addWidget(label_author, 1, 2, 1, 1);

        lineEdit_author = new QLineEdit(groupBox_info);
        lineEdit_author->setObjectName(QStringLiteral("lineEdit_author"));

        gridLayout_form->addWidget(lineEdit_author, 1, 3, 1, 1);

        label_publisher = new QLabel(groupBox_info);
        label_publisher->setObjectName(QStringLiteral("label_publisher"));

        gridLayout_form->addWidget(label_publisher, 2, 0, 1, 1);

        lineEdit_publisher = new QLineEdit(groupBox_info);
        lineEdit_publisher->setObjectName(QStringLiteral("lineEdit_publisher"));

        gridLayout_form->addWidget(lineEdit_publisher, 2, 1, 1, 1);

        label_type = new QLabel(groupBox_info);
        label_type->setObjectName(QStringLiteral("label_type"));

        gridLayout_form->addWidget(label_type, 2, 2, 1, 1);

        lineEdit_type = new QLineEdit(groupBox_info);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));

        gridLayout_form->addWidget(lineEdit_type, 2, 3, 1, 1);

        label_days = new QLabel(groupBox_info);
        label_days->setObjectName(QStringLiteral("label_days"));

        gridLayout_form->addWidget(label_days, 3, 0, 1, 1);

        lineEdit_days = new QLineEdit(groupBox_info);
        lineEdit_days->setObjectName(QStringLiteral("lineEdit_days"));

        gridLayout_form->addWidget(lineEdit_days, 3, 1, 1, 1);

        label_publish_date = new QLabel(groupBox_info);
        label_publish_date->setObjectName(QStringLiteral("label_publish_date"));

        gridLayout_form->addWidget(label_publish_date, 3, 2, 1, 1);

        dateEdit_publish = new QDateEdit(groupBox_info);
        dateEdit_publish->setObjectName(QStringLiteral("dateEdit_publish"));

        gridLayout_form->addWidget(dateEdit_publish, 3, 3, 1, 1);


        horizontalLayout_info->addLayout(gridLayout_form);


        verticalLayout->addWidget(groupBox_info);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName(QStringLiteral("horizontalLayout_buttons"));
        pushButton_add = new QPushButton(BooksManage);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_buttons->addWidget(pushButton_add);

        pushButton_delete = new QPushButton(BooksManage);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout_buttons->addWidget(pushButton_delete);

        pushButton_update = new QPushButton(BooksManage);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));

        horizontalLayout_buttons->addWidget(pushButton_update);

        pushButton_search = new QPushButton(BooksManage);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout_buttons->addWidget(pushButton_search);


        verticalLayout->addLayout(horizontalLayout_buttons);

        groupBox_table = new QGroupBox(BooksManage);
        groupBox_table->setObjectName(QStringLiteral("groupBox_table"));
        verticalLayout_table = new QVBoxLayout(groupBox_table);
        verticalLayout_table->setObjectName(QStringLiteral("verticalLayout_table"));
        tableWidget_books = new QTableWidget(groupBox_table);
        tableWidget_books->setObjectName(QStringLiteral("tableWidget_books"));

        verticalLayout_table->addWidget(tableWidget_books);


        verticalLayout->addWidget(groupBox_table);


        retranslateUi(BooksManage);

        QMetaObject::connectSlotsByName(BooksManage);
    } // setupUi

    void retranslateUi(QWidget *BooksManage)
    {
        label_cardID->setText(QApplication::translate("BooksManage", "\345\215\241\345\217\267\357\274\232", 0));
        label_goodsID->setText(QApplication::translate("BooksManage", "\344\271\246\347\261\215\347\274\226\345\217\267\357\274\232", 0));
        label_name->setText(QApplication::translate("BooksManage", "\344\271\246\345\220\215\357\274\232", 0));
        label_author->setText(QApplication::translate("BooksManage", "\344\275\234\350\200\205\357\274\232", 0));
        label_publisher->setText(QApplication::translate("BooksManage", "\345\207\272\347\211\210\347\244\276\357\274\232", 0));
        label_type->setText(QApplication::translate("BooksManage", "\345\233\276\344\271\246\347\261\273\345\236\213\357\274\232", 0));
        label_days->setText(QApplication::translate("BooksManage", "\345\217\257\345\200\237\345\244\251\346\225\260\357\274\232", 0));
        label_publish_date->setText(QApplication::translate("BooksManage", "\345\207\272\347\211\210\346\227\266\351\227\264\357\274\232", 0));
        dateEdit_publish->setDisplayFormat(QApplication::translate("BooksManage", "yyyy-MM-dd", 0));
        pushButton_add->setText(QApplication::translate("BooksManage", "\346\267\273\345\212\240", 0));
        pushButton_delete->setText(QApplication::translate("BooksManage", "\345\210\240\351\231\244", 0));
        pushButton_update->setText(QApplication::translate("BooksManage", "\344\277\256\346\224\271", 0));
        pushButton_search->setText(QApplication::translate("BooksManage", "\346\220\234\347\264\242", 0));
        groupBox_table->setTitle(QApplication::translate("BooksManage", "\345\233\276\344\271\246\345\210\227\350\241\250", 0));
        Q_UNUSED(BooksManage);
    } // retranslateUi

};

namespace Ui {
    class BooksManage: public Ui_BooksManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSMANAGE_H
