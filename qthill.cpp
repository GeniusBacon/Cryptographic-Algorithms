#include "qthill.h"
#include "ui_qthill.h"

#include "T4_hillcipher.h"
#include <QStringList>
#include <QComboBox>
#include <string>
#include <vector>

qtHill::qtHill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtHill)
{
    ui->setupUi(this);
    QStringList list_items;
    list_items << "2x2 matrix" << "3x3 matrix";

    ui->comboBox->addItems(list_items);
}

qtHill::~qtHill()
{
    delete ui;
}

void qtHill::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
    {
        ui->Key13Label->setVisible(false);
        ui->Key23Label->setVisible(false);
        ui->Key31Label->setVisible(false);
        ui->Key32Label->setVisible(false);
        ui->Key33Label->setVisible(false);
    }
    else if (index == 1)
    {
        ui->Key13Label->setVisible(true);
        ui->Key23Label->setVisible(true);
        ui->Key31Label->setVisible(true);
        ui->Key32Label->setVisible(true);
        ui->Key33Label->setVisible(true);
    }
}


void qtHill::on_EncryptPushButton_clicked()
{
    T4_HillCipher obj_hill;
    QString plain, output, key;
    vector<int> keyvec, pvec;

    plain = ui->PlainLineEdit->text();
    string p = plain.toStdString(), out="";

    for (int i=0; i<p.size(); i++)
    {
        char c = tolower(p[i]);
        pvec.push_back(c - 'a');

    }


    if (ui->comboBox->currentIndex() == 0)
    {
        key = ui->Key11Label->text();                                 // 17 17 5 21 18 21 2 2 19
        keyvec.push_back(key.toInt());    //17 17 21 18 5 21 2 2 19

        key = ui->Key12Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key21Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key22Label->text();
        keyvec.push_back(key.toInt());
    }


     if (ui->comboBox->currentIndex() == 1)
     {
        key = ui->Key11Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key12Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key13Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key21Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key22Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key23Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key31Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key32Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key33Label->text();
        keyvec.push_back(key.toInt());
     }

     vector <int> ovec = obj_hill.Encrypt(pvec, keyvec);
     for (int i=0; i<ovec.size(); i++)
     {
         out += (ovec[i] + 'a');
     }
     output = QString::fromStdString(out);
     ui->OutputTextBrowser->setText(output);
}


void qtHill::on_DecryptPushButton_clicked()
{
    T4_HillCipher obj_hill;
    QString cipher, output, key;
    vector<int> keyvec, cvec;

    cipher = ui->CipherLineEdit->text();
    string c = cipher.toStdString(), out="";

    for (int i=0; i<c.size(); i++)
    {
        char ch = tolower(c[i]);
        cvec.push_back(ch - 'a');

    }


    if (ui->comboBox->currentIndex() == 0)
    {
        key = ui->Key11Label->text();                                 // 17 17 5 21 18 21 2 2 19
        keyvec.push_back(key.toInt());    //17 17 21 18 5 21 2 2 19

        key = ui->Key12Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key21Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key22Label->text();
        keyvec.push_back(key.toInt());
    }


     if (ui->comboBox->currentIndex() == 1)
     {
        key = ui->Key11Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key12Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key13Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key21Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key22Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key23Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key31Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key32Label->text();
        keyvec.push_back(key.toInt());

        key = ui->Key33Label->text();
        keyvec.push_back(key.toInt());
     }

     vector <int> ovec = obj_hill.Decrypt(cvec, keyvec);
     for (int i=0; i<ovec.size(); i++)
     {
         out += (ovec[i] + 'a');
     }
     output = QString::fromStdString(out);
     ui->OutputTextBrowser->setText(output);

}


void qtHill::on_AnalyzePushButton_clicked()
{



    if (ui->comboBox->currentIndex() == 0)
    {

    }

    if (ui->comboBox->currentIndex() == 1)
    {

    }

}

