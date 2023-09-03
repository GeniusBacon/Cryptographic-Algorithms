#ifndef QTRSA_H
#define QTRSA_H

#include <QDialog>

namespace Ui {
class qtrsa;
}

class qtrsa : public QDialog
{
    Q_OBJECT

public:
    explicit qtrsa(QWidget *parent = nullptr);
    ~qtrsa();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

private:
    Ui::qtrsa *ui;
};

#endif // QTRSA_H
