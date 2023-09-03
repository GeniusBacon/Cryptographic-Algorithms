#include "qtcolumnar.h"
#include "T4_Columnar.h"
#include "ui_qtcolumnar.h"
#include <string>
using namespace std;

qtcolumnar::qtcolumnar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtcolumnar)
{
    ui->setupUi(this);
}

qtcolumnar::~qtcolumnar()
{
    delete ui;
}

void qtcolumnar::on_EncryptPushButton_clicked()
{
    T4_Columnar obj_columnar;
    QString Plain, Key, Output;
    vector<int> keyvec, pvec;

    Plain = ui->PlainLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string K = Key.toStdString(),p = Plain.toStdString(), out="";

    for (int i=0; i<K.size(); i++)
    {
        keyvec.push_back(K[i]-'0');
    }
    out = obj_columnar.Encrypt(p, keyvec);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}


void qtcolumnar::on_DecryptPushButton_clicked()
{
    T4_Columnar obj_columnar;
    QString Cipher, Key, Output;
    vector<int> keyvec, pvec;

    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string K = Key.toStdString(),c = Cipher.toStdString(), out="";

    for (int i=0; i<K.size(); i++)
    {
        keyvec.push_back(K[i]-'0');
    }
    out = obj_columnar.Decrypt(c, keyvec);
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}




void qtcolumnar::on_AnalyzePushButton_clicked()
{
    T4_Columnar obj_columnar;
    QString Cipher, Key, Output , Plain;
    vector<int> keyvec, pvec;
    string outvec;
    Plain = ui->PlainLineEdit->text();
    Cipher = ui->CipherLineEdit->text();
    Key = ui->KeyLineEdit->text();
    string p = Plain.toStdString(),c = Cipher.toStdString();
    list<int> out_int;
    out_int = obj_columnar.Analyze(p, c);

    for (auto v : out_int)
        outvec += (char)(48+v);


    Output = QString::fromStdString(outvec);

    ui->OutputTextBrowser->setText(Output);
}

