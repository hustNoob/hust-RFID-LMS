/********************************************************************************
** Form generated from reading UI file 'usermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

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

class Ui_UserManage
{
public:
    QVBoxLayout *verticalLayout_main;
    QGroupBox *groupBox_userinfo;
    QHBoxLayout *horizontalLayout_userinfo;
    QLabel *label_cardid;
    QLineEdit *lineEdit_cardid;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_gender;
    QLineEdit *lineEdit_gender;
    QLabel *label_age;
    QLineEdit *lineEdit_age;
    QLabel *label_tel;
    QLineEdit *lineEdit_tel;
    QHBoxLayout *horizontalLayout_buttons;
    QPushButton *pushButton_add;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_update;
    QPushButton *pushButton_search;
    QSpacerItem *spacer_mainbtns;
    QGroupBox *groupBox_usertable;
    QHBoxLayout *horizontalLayout_table;
    QTableWidget *tableWidget_user;
    QHBoxLayout *horizontalLayout_editbtns;
    QPushButton *pushButton_lost;
    QPushButton *pushButton_find;
    QPushButton *pushButton_logout;
    QSpacerItem *spacer_editbtns;

    void setupUi(QWidget *UserManage)
    {
        if (UserManage->objectName().isEmpty())
            UserManage->setObjectName(QStringLiteral("UserManage"));
        verticalLayout_main = new QVBoxLayout(UserManage);
        verticalLayout_main->setObjectName(QStringLiteral("verticalLayout_main"));
        groupBox_userinfo = new QGroupBox(UserManage);
        groupBox_userinfo->setObjectName(QStringLiteral("groupBox_userinfo"));
        horizontalLayout_userinfo = new QHBoxLayout(groupBox_userinfo);
        horizontalLayout_userinfo->setObjectName(QStringLiteral("horizontalLayout_userinfo"));
        label_cardid = new QLabel(groupBox_userinfo);
        label_cardid->setObjectName(QStringLiteral("label_cardid"));

        horizontalLayout_userinfo->addWidget(label_cardid);

        lineEdit_cardid = new QLineEdit(groupBox_userinfo);
        lineEdit_cardid->setObjectName(QStringLiteral("lineEdit_cardid"));

        horizontalLayout_userinfo->addWidget(lineEdit_cardid);

        label_name = new QLabel(groupBox_userinfo);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout_userinfo->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBox_userinfo);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout_userinfo->addWidget(lineEdit_name);

        label_gender = new QLabel(groupBox_userinfo);
        label_gender->setObjectName(QStringLiteral("label_gender"));

        horizontalLayout_userinfo->addWidget(label_gender);

        lineEdit_gender = new QLineEdit(groupBox_userinfo);
        lineEdit_gender->setObjectName(QStringLiteral("lineEdit_gender"));

        horizontalLayout_userinfo->addWidget(lineEdit_gender);

        label_age = new QLabel(groupBox_userinfo);
        label_age->setObjectName(QStringLiteral("label_age"));

        horizontalLayout_userinfo->addWidget(label_age);

        lineEdit_age = new QLineEdit(groupBox_userinfo);
        lineEdit_age->setObjectName(QStringLiteral("lineEdit_age"));

        horizontalLayout_userinfo->addWidget(lineEdit_age);

        label_tel = new QLabel(groupBox_userinfo);
        label_tel->setObjectName(QStringLiteral("label_tel"));

        horizontalLayout_userinfo->addWidget(label_tel);

        lineEdit_tel = new QLineEdit(groupBox_userinfo);
        lineEdit_tel->setObjectName(QStringLiteral("lineEdit_tel"));

        horizontalLayout_userinfo->addWidget(lineEdit_tel);


        verticalLayout_main->addWidget(groupBox_userinfo);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName(QStringLiteral("horizontalLayout_buttons"));
        pushButton_add = new QPushButton(UserManage);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_buttons->addWidget(pushButton_add);

        pushButton_delete = new QPushButton(UserManage);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));

        horizontalLayout_buttons->addWidget(pushButton_delete);

        pushButton_update = new QPushButton(UserManage);
        pushButton_update->setObjectName(QStringLiteral("pushButton_update"));

        horizontalLayout_buttons->addWidget(pushButton_update);

        pushButton_search = new QPushButton(UserManage);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout_buttons->addWidget(pushButton_search);

        spacer_mainbtns = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_buttons->addItem(spacer_mainbtns);


        verticalLayout_main->addLayout(horizontalLayout_buttons);

        groupBox_usertable = new QGroupBox(UserManage);
        groupBox_usertable->setObjectName(QStringLiteral("groupBox_usertable"));
        horizontalLayout_table = new QHBoxLayout(groupBox_usertable);
        horizontalLayout_table->setObjectName(QStringLiteral("horizontalLayout_table"));
        tableWidget_user = new QTableWidget(groupBox_usertable);
        tableWidget_user->setObjectName(QStringLiteral("tableWidget_user"));

        horizontalLayout_table->addWidget(tableWidget_user);


        verticalLayout_main->addWidget(groupBox_usertable);

        horizontalLayout_editbtns = new QHBoxLayout();
        horizontalLayout_editbtns->setObjectName(QStringLiteral("horizontalLayout_editbtns"));
        pushButton_lost = new QPushButton(UserManage);
        pushButton_lost->setObjectName(QStringLiteral("pushButton_lost"));

        horizontalLayout_editbtns->addWidget(pushButton_lost);

        pushButton_find = new QPushButton(UserManage);
        pushButton_find->setObjectName(QStringLiteral("pushButton_find"));

        horizontalLayout_editbtns->addWidget(pushButton_find);

        pushButton_logout = new QPushButton(UserManage);
        pushButton_logout->setObjectName(QStringLiteral("pushButton_logout"));

        horizontalLayout_editbtns->addWidget(pushButton_logout);

        spacer_editbtns = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_editbtns->addItem(spacer_editbtns);


        verticalLayout_main->addLayout(horizontalLayout_editbtns);


        retranslateUi(UserManage);

        QMetaObject::connectSlotsByName(UserManage);
    } // setupUi

    void retranslateUi(QWidget *UserManage)
    {
        UserManage->setWindowTitle(QApplication::translate("UserManage", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        groupBox_userinfo->setTitle(QApplication::translate("UserManage", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label_cardid->setText(QApplication::translate("UserManage", "\345\215\241\345\217\267\357\274\232", 0));
        label_name->setText(QApplication::translate("UserManage", "\345\247\223\345\220\215\357\274\232", 0));
        label_gender->setText(QApplication::translate("UserManage", "\346\200\247\345\210\253\357\274\232", 0));
        label_age->setText(QApplication::translate("UserManage", "\345\271\264\351\276\204\357\274\232", 0));
        label_tel->setText(QApplication::translate("UserManage", "\346\211\213\346\234\272\345\217\267\357\274\232", 0));
        pushButton_add->setText(QApplication::translate("UserManage", "\346\267\273\345\212\240", 0));
        pushButton_delete->setText(QApplication::translate("UserManage", "\345\210\240\351\231\244", 0));
        pushButton_update->setText(QApplication::translate("UserManage", "\344\277\256\346\224\271", 0));
        pushButton_search->setText(QApplication::translate("UserManage", "\346\220\234\347\264\242", 0));
        groupBox_usertable->setTitle(QApplication::translate("UserManage", "\347\224\250\346\210\267\345\210\227\350\241\250", 0));
        pushButton_lost->setText(QApplication::translate("UserManage", "\346\214\202\345\244\261", 0));
        pushButton_find->setText(QApplication::translate("UserManage", "\345\217\226\346\266\210\346\214\202\345\244\261", 0));
        pushButton_logout->setText(QApplication::translate("UserManage", "\346\263\250\351\224\200\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class UserManage: public Ui_UserManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
