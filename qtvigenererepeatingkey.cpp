#include "qtvigenererepeatingkey.h"
#include "T4_vigenererepeatingkey.h"
#include "ui_qtvigenererepeatingkey.h"

qtvigenereRepeatingKey::qtvigenereRepeatingKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtvigenereRepeatingKey)
{
    ui->setupUi(this);
}

qtvigenereRepeatingKey::~qtvigenereRepeatingKey()
{
    delete ui;
}

void qtvigenereRepeatingKey::on_EncryptPushButton_clicked()
{
    T4_VigenereRepeatingKey obj_vr;
    QString Plain, Key, Output;
    obj_vr.createVigenereTable();
    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_vr.Encrypt_repeating(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtvigenereRepeatingKey::on_DecryptPushButton_clicked()
{
    T4_VigenereRepeatingKey obj_vr;
    QString Cipher, Key, Output;
    obj_vr.createVigenereTable();
    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_vr.Decrypt_repeating(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtvigenereRepeatingKey::on_AnalyzePushButton_clicked()
{
    T4_VigenereRepeatingKey obj_vr;
    QString Plain, Cipher, Output;
    obj_vr.createVigenereTable();
    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    string out = obj_vr.Analyse_repeating(Plain.toStdString(), Cipher.toStdString());
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output);
}

