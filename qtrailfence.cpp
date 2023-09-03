#include "qtrailfence.h"
#include "T4_Railfence.h"
#include "ui_qtrailfence.h"

qtrailfence::qtrailfence(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtrailfence)
{
    ui->setupUi(this);
}

qtrailfence::~qtrailfence()
{
    delete ui;
}

void qtrailfence::on_EncryptPushButton_clicked()
{
    T4_Railfence obj_railfence;
    QString Plain, Key, Output;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    int k = Key.toInt();
    string out = obj_railfence.encrypt_railfence(Plain.toStdString(), k);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}



void qtrailfence::on_DecryptPushButton_clicked()
{
    T4_Railfence obj_railfence;
    QString  Cipher, Key, Output;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    int k = Key.toInt();
    string out = obj_railfence.decrypt_railfence(Cipher.toStdString(), k);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtrailfence::on_AnalyzePushButton_clicked()
{
    T4_Railfence obj_railfence;
    QString Plain, Cipher, Output;

    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    int out_int = obj_railfence.analyze_railfence(Plain.toStdString(), Cipher.toStdString());
    string out = to_string(out_int);
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output);
}

