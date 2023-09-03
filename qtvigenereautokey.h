#ifndef QTVIGENEREAUTOKEY_H
#define QTVIGENEREAUTOKEY_H

#include <QDialog>

namespace Ui {
class qtvigenereAutoKey;
}

class qtvigenereAutoKey : public QDialog
{
    Q_OBJECT

public:
    explicit qtvigenereAutoKey(QWidget *parent = nullptr);
    ~qtvigenereAutoKey();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::qtvigenereAutoKey *ui;
};

#endif // QTVIGENEREAUTOKEY_H
