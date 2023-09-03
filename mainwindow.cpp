#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CaesarButton_clicked()
{
    c = new QtCaesar(this);
    c->setStyleSheet("QtCaesar {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
    c->show();
}

void MainWindow::on_ColumnarButton_clicked()
{
    co = new qtcolumnar(this);
    co->setStyleSheet("qtcolumnar {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    co->show();
}

void MainWindow::on_HillPushButton_clicked()
{
    h = new qtHill(this);
    h->setStyleSheet("qtHill {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
    h->show();
}

void MainWindow::on_MonoalphabeticButton_clicked()
{
    m = new qtmonoalphabetic(this);
    m->setStyleSheet("qtmonoalphabetic {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    m->show();
}

void MainWindow::on_playfairButton_clicked()
{
    p = new qtplayfair(this);
    p->setStyleSheet("qtplayfair {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    p->show();
}

void MainWindow::on_RailfenceButton_clicked()
{
    r = new qtrailfence(this);
    r->setStyleSheet("qtrailfence {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    r->show();
}

void MainWindow::on_VigenereRepeatingKeyButton_clicked()
{
    vr = new qtvigenereRepeatingKey(this);
    vr->setStyleSheet("qtvigenereRepeatingKey {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    vr->show();
}

void MainWindow::on_VigenereAutoKeyButton_clicked()
{
    va = new qtvigenereAutoKey(this);
    va->setStyleSheet("qtvigenereAutoKey {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    va->show();
}

void MainWindow::on_DesButton_clicked()
{
    d = new qtdes(this);
    d->setStyleSheet("qtdes {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    d->show();
}


void MainWindow::on_AesButton_clicked()
{
    a = new qtaes(this);
    a->setStyleSheet("qtaes {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    a->show();
}


void MainWindow::on_RsaButton_clicked()
{
    rs = new qtrsa(this);
    rs->setStyleSheet("qtrsa {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    rs->show();
}


void MainWindow::on_Md5Button_clicked()
{
    md = new qtmd5(this);
    md->setStyleSheet("qtmd5 {background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");

    md->show();

}

