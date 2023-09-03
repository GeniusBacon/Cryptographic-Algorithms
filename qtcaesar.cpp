#include "qtcaesar.h"
#include "ui_qtcaesar.h"
#include "T4_Caesar.h"


QtCaesar::QtCaesar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtCaesar)
{
    ui->setupUi(this);

}

QtCaesar::~QtCaesar()
{
    delete ui;
}

void QtCaesar::on_EncryptPushButton_clicked()
{
    T4_Caesar obj_caesar;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    int k = Key.toInt();
    string out = obj_caesar.Encrypt(Plain.toStdString(), k);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void QtCaesar::on_DecryptPushButton_clicked()
{
    T4_Caesar obj_caesar;
    QString  Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    int k = Key.toInt();
    string out = obj_caesar.Decrypt(Cipher.toStdString(), k);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void QtCaesar::on_AnalyzePushButton_clicked()
{
    T4_Caesar obj_caesar;
    QString Plain, Cipher, Output;

    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    int out_int = obj_caesar.Analyze(Plain.toStdString(), Cipher.toStdString());
    string out = to_string(out_int);
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output);
}

