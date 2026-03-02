#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QSqlDatabase>
#include <QLabel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/yazilimci20/OneDrive/Belgeler/GorselProgramlama/231229021_MuhammetBilal_Erkoc_final/dbfinal.db");
    db.open();

    sorgu = new QSqlQuery(db);
    guncelle = new QSqlQuery(db);
    model = new QSqlQueryModel();

    listele();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listele()
{
    //derste işlenen Kaynaklar 08.12.2025 dosyasındaki yapı

    // yapilacaklar tablosu kodları
    sorgu->prepare("SELECT Gorev, ID FROM gorevler WHERE Durumu = 0");
    sorgu->exec();
    model->setQuery(*sorgu);

    ui->yapilacaklar->setColumnCount(2);
    ui->yapilacaklar->setRowCount(model->rowCount());
    QStringList solBaslik = {"Görev", "Tamamlandı"};
    ui->yapilacaklar->setHorizontalHeaderLabels(solBaslik);

    for(int i = 0; i < model->rowCount(); ++i) {

        ui->yapilacaklar->setCellWidget(i, 0, new QLabel(model->index(i, 0).data().toString()));

        QCheckBox *kutu = new QCheckBox();

        kutu->setObjectName(model->index(i, 1).data().toString());

        ui->yapilacaklar->setCellWidget(i, 1, kutu);

    }

    // yapilanlar tablosu kodları
    sorgu->prepare("SELECT Gorev, ID FROM gorevler WHERE Durumu = 1");
    sorgu->exec();
    model->setQuery(*sorgu);

    ui->yapilanlar->setColumnCount(2);
    ui->yapilanlar->setRowCount(model->rowCount());
    QStringList sagBaslik = {"Görev", "Tamamlandı"};
    ui->yapilanlar->setHorizontalHeaderLabels(sagBaslik);

    for(int i = 0; i < model->rowCount(); ++i) {

        ui->yapilanlar->setCellWidget(i, 0, new QLabel(model->index(i, 0).data().toString()));

        QCheckBox *kutu = new QCheckBox();
        kutu->setObjectName(model->index(i, 1).data().toString());
        kutu->setChecked(true);
        ui->yapilanlar->setCellWidget(i, 1, kutu);

    }

}



void MainWindow::on_gorev_ekle_clicked()
{
    // //derste işlenen Kaynaklar 27.11.2025 dosyasındaki yapı
    sorgu->prepare("INSERT INTO gorevler (Gorev) VALUES (?)");
    sorgu->addBindValue(ui->gorevYaz->text());
    sorgu->exec() ;
    ui->gorevYaz->clear();
    listele();

}


void MainWindow::on_btn_tamamla_clicked()
{
    // burdaki kodları listele fonksiyonundaki döngüleri baz alara yazdım
    for(int i = 0; i < ui->yapilacaklar->rowCount(); ++i) {
        QCheckBox *kontrol = (QCheckBox *) ui->yapilacaklar->cellWidget(i, 1);
        if (kontrol->isChecked()) {

            QString id = kontrol->objectName();

            guncelle->prepare("UPDATE gorevler SET Durumu = 1 WHERE ID = ?");
            guncelle->addBindValue(id);
            guncelle->exec();
        }
    }

    listele();
}

void MainWindow::on_btn_tamamlama_clicked()
{
    // burdaki kodları listele fonksiyonundaki döngüleri baz alara yazdım
    for(int i = 0; i < ui->yapilanlar->rowCount(); ++i) {
        QCheckBox *kontrol = (QCheckBox *) ui->yapilanlar->cellWidget(i, 1);
        if (!(kontrol->isChecked())) {
            QString id = kontrol->objectName();

            guncelle->prepare("UPDATE gorevler SET Durumu = 0 WHERE ID = ?");
            guncelle->addBindValue(id);
            guncelle->exec();
        }
    }
    listele();
}

