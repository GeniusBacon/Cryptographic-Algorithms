#include "qtvigenereautokey.h"
#include "T4_vigenereautokey.h"
#include "ui_qtvigenereautokey.h"

qtvigenereAutoKey::qtvigenereAutoKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtvigenereAutoKey)
{
    ui->setupUi(this);
}

qtvigenereAutoKey::~qtvigenereAutoKey()
{
    delete ui;
}

void qtvigenereAutoKey::on_EncryptPushButton_clicked()
{
    T4_VigenereAutoKey obj_va;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_va.Encrypt(Plain.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtvigenereAutoKey::on_DecryptPushButton_clicked()
{
    T4_VigenereAutoKey obj_va;
    QString Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string out = obj_va.Decrypt(Cipher.toStdString(), Key.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtvigenereAutoKey::on_AnalyzePushButton_clicked()
{
    T4_VigenereAutoKey obj_va;
    QString Plain, Cipher, Output;

    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    string out = obj_va.Analyse(Plain.toStdString(), Cipher.toStdString());
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output);
}

