/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_5;
    QLabel *img_lbl;
    QLabel *img_bg_lbl;
    QLabel *ctrl_arrow_lbl;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *img_his_lbl;
    QLabel *label;
    QLabel *ctrl_mouse_lbl;
    QLabel *label_3;
    QPushButton *change_bg_btn;
    QLabel *print_percent_lbl;
    QPushButton *browser_btn;
    QPushButton *start_program_btn;
    QPushButton *start_process_btn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QCheckBox *show_per_cb;
    QCheckBox *sub_bg_cb;
    QCheckBox *equal_his_cb;
    QCheckBox *draw_his_cb;
    QCheckBox *ctrl_mouse_cb;
    QCheckBox *ctrl_arrow_cb;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(840, 350);
        MainWindow->setMinimumSize(QSize(840, 350));
        MainWindow->setMaximumSize(QSize(840, 350));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 0, 161, 20));
        label_5->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        img_lbl = new QLabel(centralWidget);
        img_lbl->setObjectName(QStringLiteral("img_lbl"));
        img_lbl->setGeometry(QRect(10, 30, 320, 240));
        img_lbl->setStyleSheet(QStringLiteral("background-color: rgb(69, 209, 0);"));
        img_bg_lbl = new QLabel(centralWidget);
        img_bg_lbl->setObjectName(QStringLiteral("img_bg_lbl"));
        img_bg_lbl->setGeometry(QRect(460, 30, 160, 120));
        img_bg_lbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 0);"));
        ctrl_arrow_lbl = new QLabel(centralWidget);
        ctrl_arrow_lbl->setObjectName(QStringLiteral("ctrl_arrow_lbl"));
        ctrl_arrow_lbl->setGeometry(QRect(660, 190, 160, 120));
        ctrl_arrow_lbl->setStyleSheet(QLatin1String("background-color: rgb(205, 190, 255);\n"
"border: 2px solid #222222;\n"
"border-radius: 10px;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 160, 161, 20));
        label_2->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(660, 160, 141, 20));
        label_4->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        img_his_lbl = new QLabel(centralWidget);
        img_his_lbl->setObjectName(QStringLiteral("img_his_lbl"));
        img_his_lbl->setGeometry(QRect(460, 190, 160, 120));
        img_his_lbl->setStyleSheet(QStringLiteral("background-color: rgb(255, 175, 177);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 0, 161, 20));
        label->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        ctrl_mouse_lbl = new QLabel(centralWidget);
        ctrl_mouse_lbl->setObjectName(QStringLiteral("ctrl_mouse_lbl"));
        ctrl_mouse_lbl->setGeometry(QRect(660, 30, 160, 120));
        ctrl_mouse_lbl->setStyleSheet(QLatin1String("alternate-background-color: rgb(255, 255, 255);\n"
"background-color: rgb(103, 248, 255);\n"
"border: 2px solid #222222;\n"
"border-radius: 10px;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 0, 161, 20));
        label_3->setStyleSheet(QStringLiteral("font: 14pt \"Times New Roman\";"));
        change_bg_btn = new QPushButton(centralWidget);
        change_bg_btn->setObjectName(QStringLiteral("change_bg_btn"));
        change_bg_btn->setGeometry(QRect(340, 280, 100, 31));
        change_bg_btn->setStyleSheet(QLatin1String("border: 2px solid #222222;\n"
"border-radius: 10px;\n"
"QPushButton#change_bg_btn:pressed {\n"
"     background-color: rgb(224, 0, 0);     \n"
"}"));
        print_percent_lbl = new QLabel(centralWidget);
        print_percent_lbl->setObjectName(QStringLiteral("print_percent_lbl"));
        print_percent_lbl->setGeometry(QRect(340, 30, 101, 51));
        print_percent_lbl->setStyleSheet(QLatin1String("background-color: rgb(255, 217, 24);\n"
"border: 2px solid #222222;\n"
"border-radius: 10px;\n"
"font: 75 20pt \"Times New Roman\";"));
        browser_btn = new QPushButton(centralWidget);
        browser_btn->setObjectName(QStringLiteral("browser_btn"));
        browser_btn->setGeometry(QRect(10, 280, 100, 31));
        browser_btn->setStyleSheet(QLatin1String("border: 2px solid #222222;\n"
"border-radius: 10px;\n"
"QPushButton#browser_btn:pressed {\n"
"     background-color: rgb(224, 0, 0);     \n"
" }\n"
""));
        start_program_btn = new QPushButton(centralWidget);
        start_program_btn->setObjectName(QStringLiteral("start_program_btn"));
        start_program_btn->setGeometry(QRect(120, 280, 100, 31));
        start_program_btn->setStyleSheet(QLatin1String("border: 2px solid #222222;\n"
"border-radius: 10px;\n"
" QPushButton#start_program_btn:pressed {\n"
"     background-color: rgb(224, 0, 0);     \n"
" }"));
        start_process_btn = new QPushButton(centralWidget);
        start_process_btn->setObjectName(QStringLiteral("start_process_btn"));
        start_process_btn->setGeometry(QRect(230, 280, 100, 31));
        start_process_btn->setStyleSheet(QLatin1String("border: 2px solid #222222;\n"
"border-radius: 10px;\n"
"QPushButton#start_process_btn:pressed {\n"
"     background-color: rgb(224, 0, 0);     \n"
"}"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(340, 110, 101, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        show_per_cb = new QCheckBox(widget);
        show_per_cb->setObjectName(QStringLiteral("show_per_cb"));

        verticalLayout->addWidget(show_per_cb);

        sub_bg_cb = new QCheckBox(widget);
        sub_bg_cb->setObjectName(QStringLiteral("sub_bg_cb"));

        verticalLayout->addWidget(sub_bg_cb);

        equal_his_cb = new QCheckBox(widget);
        equal_his_cb->setObjectName(QStringLiteral("equal_his_cb"));

        verticalLayout->addWidget(equal_his_cb);

        draw_his_cb = new QCheckBox(widget);
        draw_his_cb->setObjectName(QStringLiteral("draw_his_cb"));

        verticalLayout->addWidget(draw_his_cb);

        ctrl_mouse_cb = new QCheckBox(widget);
        ctrl_mouse_cb->setObjectName(QStringLiteral("ctrl_mouse_cb"));

        verticalLayout->addWidget(ctrl_mouse_cb);

        ctrl_arrow_cb = new QCheckBox(widget);
        ctrl_arrow_cb->setObjectName(QStringLiteral("ctrl_arrow_cb"));

        verticalLayout->addWidget(ctrl_arrow_cb);

        MainWindow->setCentralWidget(centralWidget);
        label_5->raise();
        img_lbl->raise();
        img_bg_lbl->raise();
        ctrl_arrow_lbl->raise();
        label_2->raise();
        label_4->raise();
        img_his_lbl->raise();
        label->raise();
        ctrl_mouse_lbl->raise();
        label_3->raise();
        sub_bg_cb->raise();
        equal_his_cb->raise();
        draw_his_cb->raise();
        ctrl_mouse_cb->raise();
        ctrl_arrow_cb->raise();
        show_per_cb->raise();
        change_bg_btn->raise();
        print_percent_lbl->raise();
        browser_btn->raise();
        start_program_btn->raise();
        start_process_btn->raise();
        change_bg_btn->raise();
        label_6->raise();
        label_6->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_5->setText(QApplication::translate("MainWindow", "Current Image", 0));
        img_lbl->setText(QString());
        img_bg_lbl->setText(QString());
        ctrl_arrow_lbl->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Histogram", 0));
        label_4->setText(QApplication::translate("MainWindow", "Control Arrow key", 0));
        img_his_lbl->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Background Image", 0));
        ctrl_mouse_lbl->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Control mouse", 0));
        change_bg_btn->setText(QApplication::translate("MainWindow", "Change BG", 0));
        print_percent_lbl->setText(QApplication::translate("MainWindow", "%", 0));
        browser_btn->setText(QApplication::translate("MainWindow", "Browser", 0));
        start_program_btn->setText(QApplication::translate("MainWindow", "Start Program", 0));
        start_process_btn->setText(QApplication::translate("MainWindow", "Start Process", 0));
        label_6->setText(QApplication::translate("MainWindow", "Option:", 0));
        show_per_cb->setText(QApplication::translate("MainWindow", "Show_Per", 0));
        sub_bg_cb->setText(QApplication::translate("MainWindow", "Sub_BG", 0));
        equal_his_cb->setText(QApplication::translate("MainWindow", "Equal_His", 0));
        draw_his_cb->setText(QApplication::translate("MainWindow", "Draw_His", 0));
        ctrl_mouse_cb->setText(QApplication::translate("MainWindow", "Ctrl_Mouse", 0));
        ctrl_arrow_cb->setText(QApplication::translate("MainWindow", "Ctrl_Arrow", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
