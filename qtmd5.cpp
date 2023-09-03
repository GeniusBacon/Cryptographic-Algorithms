#include "qtmd5.h"
#include "T4_md5.h"
#include "ui_qtmd5.h"

qtmd5::qtmd5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qtmd5)
{
    ui->setupUi(this);
}

qtmd5::~qtmd5()
{
    delete ui;
}

void qtmd5::on_GetHashButton_clicked()
{
    T4_md5 obj_md5;
    QString Plain, Output;

    Plain = ui->PlainLineEdit->text();
    string out = obj_md5.GetHash(Plain.toStdString());
    Output = QString::fromStdString(out);

    ui->OutputTextBrowser->setText(Output);
}

