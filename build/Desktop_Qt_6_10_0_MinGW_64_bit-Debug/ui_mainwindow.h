/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *yapilacaklar;
    QTableWidget *yapilanlar;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *gorevYaz;
    QPushButton *btn_tamamla;
    QPushButton *btn_tamamlama;
    QPushButton *gorev_ekle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1407, 713);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        yapilacaklar = new QTableWidget(centralwidget);
        yapilacaklar->setObjectName("yapilacaklar");
        yapilacaklar->setGeometry(QRect(360, 110, 321, 431));
        yapilanlar = new QTableWidget(centralwidget);
        yapilanlar->setObjectName("yapilanlar");
        yapilanlar->setGeometry(QRect(720, 110, 271, 431));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(470, 70, 141, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(810, 70, 141, 20));
        gorevYaz = new QLineEdit(centralwidget);
        gorevYaz->setObjectName("gorevYaz");
        gorevYaz->setGeometry(QRect(80, 70, 221, 28));
        btn_tamamla = new QPushButton(centralwidget);
        btn_tamamla->setObjectName("btn_tamamla");
        btn_tamamla->setGeometry(QRect(420, 570, 231, 29));
        btn_tamamlama = new QPushButton(centralwidget);
        btn_tamamlama->setObjectName("btn_tamamlama");
        btn_tamamlama->setGeometry(QRect(710, 570, 301, 29));
        gorev_ekle = new QPushButton(centralwidget);
        gorev_ekle->setObjectName("gorev_ekle");
        gorev_ekle->setGeometry(QRect(120, 110, 141, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1407, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Yap\304\261lacaklar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Yap\304\261lanlar", nullptr));
        btn_tamamla->setText(QCoreApplication::translate("MainWindow", "Secilen G\303\266revleri Tamamla", nullptr));
        btn_tamamlama->setText(QCoreApplication::translate("MainWindow", "Se\303\247ilmemi\305\237 G\303\266revleri Tamamlanmam\304\261\305\237 Yap", nullptr));
        gorev_ekle->setText(QCoreApplication::translate("MainWindow", "Yeni G\303\266rev Ekle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
