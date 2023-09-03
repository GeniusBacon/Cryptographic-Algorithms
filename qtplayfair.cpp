#include "qtplayfair.h"
#include "T4_playfair.h"
#include "ui_qtplayfair.h"

qtplayfair::qtplayfair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtplayfair)
{
    ui->setupUi(this);
}

qtplayfair::~qtplayfair()
{
    delete ui;
}

void qtplayfair::on_EncryptPushButton_clicked()
{
    T4_playfair obj_playfair;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_playfair.Encrypt_playfair(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}



void qtplayfair::on_DecryptPushButton_clicked()
{
    T4_playfair obj_playfair;
    QString Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_playfair.Decrypt_playfair(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}

