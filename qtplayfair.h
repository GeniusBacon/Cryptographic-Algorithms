#ifndef QTPLAYFAIR_H
#define QTPLAYFAIR_H

#include <QDialog>

namespace Ui {
class qtplayfair;
}

class qtplayfair : public QDialog
{
    Q_OBJECT

public:
    explicit qtplayfair(QWidget *parent = nullptr);
    ~qtplayfair();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

private:
    Ui::qtplayfair *ui;
};

#endif // QTPLAYFAIR_H
