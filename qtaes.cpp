#include "qtaes.h"
#include "ui_qtaes.h"
#include "T4_AES.h"


qtaes::qtaes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtaes)
{
    ui->setupUi(this);
}

qtaes::~qtaes()
{
    delete ui;
}

void qtaes::on_EncryptPushButton_clicked()
{
    T4_AES obj_aes;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_aes.Encrypt(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtaes::on_DecryptPushButton_clicked()
{
    T4_AES obj_aes;
    QString Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_aes.Decrypt(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}

