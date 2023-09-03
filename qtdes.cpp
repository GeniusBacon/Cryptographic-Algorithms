#include "qtdes.h"
#include "T4_DES.h"
#include "ui_qtdes.h"

qtdes::qtdes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtdes)
{
    ui->setupUi(this);
}

qtdes::~qtdes()
{
    delete ui;
}

void qtdes::on_EncryptPushButton_clicked()
{
    T4_DES obj_des;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_des.Encrypt(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtdes::on_DecryptPushButton_clicked()
{
    T4_DES obj_des;
    QString Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_des.Decrypt(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}

