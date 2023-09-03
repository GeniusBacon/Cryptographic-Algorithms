#ifndef QTMONOALPHABETIC_H
#define QTMONOALPHABETIC_H

#include <QDialog>

namespace Ui {
class qtmonoalphabetic;
}

class qtmonoalphabetic : public QDialog
{
    Q_OBJECT

public:
    explicit qtmonoalphabetic(QWidget *parent = nullptr);
    ~qtmonoalphabetic();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::qtmonoalphabetic *ui;
};

#endif // QTMONOALPHABETIC_H
