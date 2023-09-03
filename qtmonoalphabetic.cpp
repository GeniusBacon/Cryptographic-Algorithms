#include "qtmonoalphabetic.h"
#include "T4_monoalphabetic.h"
#include "ui_qtmonoalphabetic.h"

qtmonoalphabetic::qtmonoalphabetic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtmonoalphabetic)
{
    ui->setupUi(this);
}

qtmonoalphabetic::~qtmonoalphabetic()
{
    delete ui;
}

void qtmonoalphabetic::on_EncryptPushButton_clicked()
{
    T4_monoalphabetic obj_mono;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_mono.Encrypt_Monoalphabetic(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);

}


void qtmonoalphabetic::on_DecryptPushButton_clicked()
{
    T4_monoalphabetic obj_mono;
    QString Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_mono.Decrypt_Monoalphabetic(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtmonoalphabetic::on_AnalyzePushButton_clicked()
{
    T4_monoalphabetic obj_mono;
    QString Plain, Cipher, Output;

    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    string out = obj_mono.AnalyzeUsingCharFrequency( Cipher.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}

