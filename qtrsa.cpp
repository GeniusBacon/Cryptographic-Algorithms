#include "qtrsa.h"
#include "T4_RSA.h"
#include "ui_qtrsa.h"
using namespace std ;

qtrsa::qtrsa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtrsa)
{
    ui->setupUi(this);
}

qtrsa::~qtrsa()
{
    delete ui;
}

void qtrsa::on_EncryptPushButton_clicked()
{
    T4_RSA obj_rsa;
    QString Plain, Cipher , P , Q , Output;

    Plain = ui->PlainLineEdit->text();
    int plain = Plain.toInt();
    P = ui->PLineEdit->text();
    int p = P.toInt();
    Q = ui->qLineEdit->text();
    int q = Q.toInt();

    int out_int = obj_rsa.rsa_encrypt(p , q , plain);
    string out = to_string(out_int);
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output); ;

}


void qtrsa::on_DecryptPushButton_clicked()
{
    T4_RSA obj_rsa;
    QString Plain, Cipher , P , Q , Output;

    Cipher = ui->CipherLineEdit->text();
    int cipher = Cipher.toInt();
    P = ui->PLineEdit->text();
    int p = P.toInt();
    Q = ui->qLineEdit->text();
    int q = Q.toInt();

    int out_int = obj_rsa.rsa_decrypt(p , q , cipher);
    string out = to_string(out_int);
    Output = QString::fromStdString(out);
    ui->OutputTextBrowser->setText(Output); ;


}

