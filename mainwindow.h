#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void listele();

private slots:
    void on_gorev_ekle_clicked();
    void on_btn_tamamla_clicked();
    void on_btn_tamamlama_clicked();

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlQuery *sorgu,*guncelle;
    QSqlQueryModel *model;
};
#endif // MAINWINDOW_H
