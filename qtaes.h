#ifndef QTAES_H
#define QTAES_H

#include <QDialog>

namespace Ui {
class qtaes;
}

class qtaes : public QDialog
{
    Q_OBJECT

public:
    explicit qtaes(QWidget *parent = nullptr);
    ~qtaes();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

private:
    Ui::qtaes *ui;
};

#endif // QTAES_H
