/********************************************************************************
** Form generated from reading UI file 'borrow_return.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_RETURN_H
#define UI_BORROW_RETURN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Borrow_Return
{
public:
    QGridLayout *gridLayout_main;
    QGroupBox *groupBox_user;
    QVBoxLayout *verticalLayout_user;
    QHBoxLayout *hLayout_cardid;
    QLabel *label_cardid;
    QLineEdit *lineEdit_cardid;
    QHBoxLayout *hLayout_name;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QHBoxLayout *hLayout_gender;
    QLabel *label_gender;
    QLineEdit *lineEdit_gender;
    QHBoxLayout *hLayout_age;
    QLabel *label_age;
    QLineEdit *lineEdit_age;
    QHBoxLayout *hLayout_tel;
    QLabel *label_tel;
    QLineEdit *lineEdit_tel;
    QHBoxLayout *hLayout_borrowreturn;
    QRadioButton *radioButton_borrow;
    QRadioButton *radioButton_return;
    QGroupBox *groupBox_books;
    QVBoxLayout *verticalLayout_books;
    QTableWidget *tableWidget_books;
    QLabel *label_info;
    QLabel *label_status;

    void setupUi(QWidget *Borrow_Return)
    {
        if (Borrow_Return->objectName().isEmpty())
            Borrow_Return->setObjectName(QStringLiteral("Borrow_Return"));
        Borrow_Return->resize(533, 432);
        gridLayout_main = new QGridLayout(Borrow_Return);
        gridLayout_main->setObjectName(QStringLiteral("gridLayout_main"));
        groupBox_user = new QGroupBox(Borrow_Return);
        groupBox_user->setObjectName(QStringLiteral("groupBox_user"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_user->sizePolicy().hasHeightForWidth());
        groupBox_user->setSizePolicy(sizePolicy);
        verticalLayout_user = new QVBoxLayout(groupBox_user);
        verticalLayout_user->setObjectName(QStringLiteral("verticalLayout_user"));
        hLayout_cardid = new QHBoxLayout();
        hLayout_cardid->setObjectName(QStringLiteral("hLayout_cardid"));
        label_cardid = new QLabel(groupBox_user);
        label_cardid->setObjectName(QStringLiteral("label_cardid"));

        hLayout_cardid->addWidget(label_cardid);

        lineEdit_cardid = new QLineEdit(groupBox_user);
        lineEdit_cardid->setObjectName(QStringLiteral("lineEdit_cardid"));
        lineEdit_cardid->setReadOnly(true);

        hLayout_cardid->addWidget(lineEdit_cardid);


        verticalLayout_user->addLayout(hLayout_cardid);

        hLayout_name = new QHBoxLayout();
        hLayout_name->setObjectName(QStringLiteral("hLayout_name"));
        label_name = new QLabel(groupBox_user);
        label_name->setObjectName(QStringLiteral("label_name"));

        hLayout_name->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBox_user);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setReadOnly(true);

        hLayout_name->addWidget(lineEdit_name);


        verticalLayout_user->addLayout(hLayout_name);

        hLayout_gender = new QHBoxLayout();
        hLayout_gender->setObjectName(QStringLiteral("hLayout_gender"));
        label_gender = new QLabel(groupBox_user);
        label_gender->setObjectName(QStringLiteral("label_gender"));

        hLayout_gender->addWidget(label_gender);

        lineEdit_gender = new QLineEdit(groupBox_user);
        lineEdit_gender->setObjectName(QStringLiteral("lineEdit_gender"));
        lineEdit_gender->setReadOnly(true);

        hLayout_gender->addWidget(lineEdit_gender);


        verticalLayout_user->addLayout(hLayout_gender);

        hLayout_age = new QHBoxLayout();
        hLayout_age->setObjectName(QStringLiteral("hLayout_age"));
        label_age = new QLabel(groupBox_user);
        label_age->setObjectName(QStringLiteral("label_age"));

        hLayout_age->addWidget(label_age);

        lineEdit_age = new QLineEdit(groupBox_user);
        lineEdit_age->setObjectName(QStringLiteral("lineEdit_age"));
        lineEdit_age->setReadOnly(true);

        hLayout_age->addWidget(lineEdit_age);


        verticalLayout_user->addLayout(hLayout_age);

        hLayout_tel = new QHBoxLayout();
        hLayout_tel->setObjectName(QStringLiteral("hLayout_tel"));
        label_tel = new QLabel(groupBox_user);
        label_tel->setObjectName(QStringLiteral("label_tel"));

        hLayout_tel->addWidget(label_tel);

        lineEdit_tel = new QLineEdit(groupBox_user);
        lineEdit_tel->setObjectName(QStringLiteral("lineEdit_tel"));
        lineEdit_tel->setReadOnly(true);

        hLayout_tel->addWidget(lineEdit_tel);


        verticalLayout_user->addLayout(hLayout_tel);

        hLayout_borrowreturn = new QHBoxLayout();
        hLayout_borrowreturn->setObjectName(QStringLiteral("hLayout_borrowreturn"));
        radioButton_borrow = new QRadioButton(groupBox_user);
        radioButton_borrow->setObjectName(QStringLiteral("radioButton_borrow"));

        hLayout_borrowreturn->addWidget(radioButton_borrow);

        radioButton_return = new QRadioButton(groupBox_user);
        radioButton_return->setObjectName(QStringLiteral("radioButton_return"));

        hLayout_borrowreturn->addWidget(radioButton_return);


        verticalLayout_user->addLayout(hLayout_borrowreturn);


        gridLayout_main->addWidget(groupBox_user, 0, 0, 1, 1);

        groupBox_books = new QGroupBox(Borrow_Return);
        groupBox_books->setObjectName(QStringLiteral("groupBox_books"));
        verticalLayout_books = new QVBoxLayout(groupBox_books);
        verticalLayout_books->setObjectName(QStringLiteral("verticalLayout_books"));
        tableWidget_books = new QTableWidget(groupBox_books);
        tableWidget_books->setObjectName(QStringLiteral("tableWidget_books"));

        verticalLayout_books->addWidget(tableWidget_books);


        gridLayout_main->addWidget(groupBox_books, 0, 1, 2, 1);

        label_info = new QLabel(Borrow_Return);
        label_info->setObjectName(QStringLiteral("label_info"));

        gridLayout_main->addWidget(label_info, 1, 0, 1, 1);

        label_status = new QLabel(Borrow_Return);
        label_status->setObjectName(QStringLiteral("label_status"));

        gridLayout_main->addWidget(label_status, 2, 0, 1, 2);


        retranslateUi(Borrow_Return);

        QMetaObject::connectSlotsByName(Borrow_Return);
    } // setupUi

    void retranslateUi(QWidget *Borrow_Return)
    {
        Borrow_Return->setWindowTitle(QApplication::translate("Borrow_Return", "\345\200\237\344\271\246\350\277\230\344\271\246", 0));
        groupBox_user->setTitle(QApplication::translate("Borrow_Return", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label_cardid->setText(QApplication::translate("Borrow_Return", "\345\215\241\345\217\267\357\274\232", 0));
        label_name->setText(QApplication::translate("Borrow_Return", "\345\247\223\345\220\215\357\274\232", 0));
        label_gender->setText(QApplication::translate("Borrow_Return", "\346\200\247\345\210\253\357\274\232", 0));
        label_age->setText(QApplication::translate("Borrow_Return", "\345\271\264\351\276\204\357\274\232", 0));
        label_tel->setText(QApplication::translate("Borrow_Return", "\346\211\213\346\234\272\357\274\232", 0));
        radioButton_borrow->setText(QApplication::translate("Borrow_Return", "\345\200\237\344\271\246", 0));
        radioButton_return->setText(QApplication::translate("Borrow_Return", "\350\277\230\344\271\246", 0));
        groupBox_books->setTitle(QApplication::translate("Borrow_Return", "\345\200\237\344\271\246\345\210\227\350\241\250", 0));
        label_info->setText(QApplication::translate("Borrow_Return", "\346\254\242\350\277\216\357\274\232", 0));
        label_status->setText(QApplication::translate("Borrow_Return", "\350\257\267\345\205\210\345\210\267\345\215\241\347\231\273\345\275\225\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Borrow_Return: public Ui_Borrow_Return {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_RETURN_H
