#ifndef QTVIGENEREREPEATINGKEY_H
#define QTVIGENEREREPEATINGKEY_H

#include <QDialog>

namespace Ui {
class qtvigenereRepeatingKey;
}

class qtvigenereRepeatingKey : public QDialog
{
    Q_OBJECT

public:
    explicit qtvigenereRepeatingKey(QWidget *parent = nullptr);
    ~qtvigenereRepeatingKey();

private slots:

    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::qtvigenereRepeatingKey *ui;
};

#endif // QTVIGENEREREPEATINGKEY_H
