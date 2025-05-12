/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Record
{
public:
    QVBoxLayout *verticalLayout_main;
    QHBoxLayout *horizontalLayout_edit;
    QLabel *label_userid;
    QLineEdit *lineEdit_userid;
    QLabel *label_bookid;
    QLineEdit *lineEdit_bookid;
    QHBoxLayout *horizontalLayout_button;
    QPushButton *pushButton_select;
    QPushButton *pushButton_delete;
    QSpacerItem *spacer_1;
    QGroupBox *groupBox_table;
    QVBoxLayout *verticalLayout_table;
    QTableWidget *tableWidget_record;
    QLabel *label_status;

    void setupUi(QWidget *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QStringLiteral("Record"));
        verticalLayout_main = new QVBoxLayout(Record);
        verticalLayout_main->setObjectName(QStringLiteral("verticalLayout_main"));
        horizontalLayout_edit = new QHBoxLayout();
        horizontalLayout_edit->setObjectName(QStringLiteral("horizontalLayout_edit"));
        label_userid = new QLabel(Record);
        label_userid->setObjectName(QStringLiteral("label_userid"));

        horizontalLayout_edit->addWidget(label_userid);

        lineEdit_userid = new QLineEdit(Record);
        lineEdit_userid->setObjectName(QStringLiteral("lineEdit_userid"));

        horizontalLayout_edit->addWidget(lineEdit_userid);

        label_bookid = new QLabel(Record);
        label_bookid->setObjectName(QStringLiteral("label_bookid"));

        horizontalLayout_edit->addWidget(label_bookid);

        lineEdit_bookid = new QLineEdit(Record);
        lineEdit_bookid->setObjectName(QStringLiteral("lineEdit_bookid"));

        horizontalLayout_edit->addWidget(lineEdit_bookid);


        verticalLayout_main->addLayout(horizontalLayout_edit);

        horizontalLayout_button = new QHBoxLayout();
        horizontalLayout_button->setObjectName(QStringLiteral("horizontalLayout_button"));
        pushButton_select = new QPushButton(Record);
        pushButton_select->setObjectName(QStringLiteral("pushButton_select"));

        horizontalLayout_button->addWidget(pushButton_select);

        pushButton_delete = new QPushButton(Record);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout_button->addWidget(pushButton_delete);

        spacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_button->addItem(spacer_1);


        verticalLayout_main->addLayout(horizontalLayout_button);

        groupBox_table = new QGroupBox(Record);
        groupBox_table->setObjectName(QStringLiteral("groupBox_table"));
        verticalLayout_table = new QVBoxLayout(groupBox_table);
        verticalLayout_table->setObjectName(QStringLiteral("verticalLayout_table"));
        tableWidget_record = new QTableWidget(groupBox_table);
        tableWidget_record->setObjectName(QStringLiteral("tableWidget_record"));

        verticalLayout_table->addWidget(tableWidget_record);


        verticalLayout_main->addWidget(groupBox_table);

        label_status = new QLabel(Record);
        label_status->setObjectName(QStringLiteral("label_status"));

        verticalLayout_main->addWidget(label_status);


        retranslateUi(Record);

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QWidget *Record)
    {
        Record->setWindowTitle(QApplication::translate("Record", "\345\200\237\351\230\205\350\256\260\345\275\225\347\256\241\347\220\206", 0));
        label_userid->setText(QApplication::translate("Record", "\347\224\250\346\210\267\345\215\241\345\217\267", 0));
        label_bookid->setText(QApplication::translate("Record", "\344\271\246\347\261\215\345\215\241\345\217\267", 0));
        pushButton_select->setText(QApplication::translate("Record", "\346\220\234\347\264\242", 0));
        pushButton_delete->setText(QApplication::translate("Record", "\345\210\240\351\231\244", 0));
        groupBox_table->setTitle(QApplication::translate("Record", "\345\200\237\344\271\246\345\210\227\350\241\250", 0));
        label_status->setText(QApplication::translate("Record", "\345\217\257\351\200\232\350\277\207\345\210\267\345\215\241\346\220\234\347\264\242\346\237\245\347\234\213\346\237\220\346\234\254\344\271\246\346\210\226\346\237\220\344\270\252\347\224\250\346\210\267\347\232\204\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
