/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_main;
    QHBoxLayout *horizontalLayout_top;
    QSpacerItem *spacer_left;
    QLabel *label_picture;
    QLabel *label_title;
    QSpacerItem *spacer_right;
    QGroupBox *groupBox_connect;
    QHBoxLayout *horizontalLayout_conn;
    QComboBox *comboBox_serial;
    QComboBox *comboBox_baud;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QTabWidget *tabWidget_main;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(744, 490);
        verticalLayout_main = new QVBoxLayout(Widget);
        verticalLayout_main->setObjectName(QStringLiteral("verticalLayout_main"));
        horizontalLayout_top = new QHBoxLayout();
        horizontalLayout_top->setObjectName(QStringLiteral("horizontalLayout_top"));
        spacer_left = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_top->addItem(spacer_left);

        label_picture = new QLabel(Widget);
        label_picture->setObjectName(QStringLiteral("label_picture"));
        label_picture->setMinimumSize(QSize(70, 70));
        label_picture->setMaximumSize(QSize(70, 70));
        label_picture->setScaledContents(true);

        horizontalLayout_top->addWidget(label_picture);

        label_title = new QLabel(Widget);
        label_title->setObjectName(QStringLiteral("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label_title->setFont(font);
        label_title->setAlignment(Qt::AlignCenter);

        horizontalLayout_top->addWidget(label_title);

        spacer_right = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_top->addItem(spacer_right);

        groupBox_connect = new QGroupBox(Widget);
        groupBox_connect->setObjectName(QStringLiteral("groupBox_connect"));
        horizontalLayout_conn = new QHBoxLayout(groupBox_connect);
        horizontalLayout_conn->setObjectName(QStringLiteral("horizontalLayout_conn"));
        comboBox_serial = new QComboBox(groupBox_connect);
        comboBox_serial->setObjectName(QStringLiteral("comboBox_serial"));

        horizontalLayout_conn->addWidget(comboBox_serial);

        comboBox_baud = new QComboBox(groupBox_connect);
        comboBox_baud->setObjectName(QStringLiteral("comboBox_baud"));

        horizontalLayout_conn->addWidget(comboBox_baud);

        pushButton_connect = new QPushButton(groupBox_connect);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout_conn->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(groupBox_connect);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout_conn->addWidget(pushButton_disconnect);


        horizontalLayout_top->addWidget(groupBox_connect);


        verticalLayout_main->addLayout(horizontalLayout_top);

        tabWidget_main = new QTabWidget(Widget);
        tabWidget_main->setObjectName(QStringLiteral("tabWidget_main"));

        verticalLayout_main->addWidget(tabWidget_main);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        label_title->setText(QApplication::translate("Widget", "\345\233\276\344\271\246\351\246\206\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        groupBox_connect->setTitle(QApplication::translate("Widget", "\350\277\236\346\216\245\346\216\247\345\210\266", 0));
        pushButton_connect->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        pushButton_disconnect->setText(QApplication::translate("Widget", "\346\226\255\345\274\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
