#ifndef QTDES_H
#define QTDES_H

#include <QDialog>

namespace Ui {
class qtdes;
}

class qtdes : public QDialog
{
    Q_OBJECT

public:
    explicit qtdes(QWidget *parent = nullptr);
    ~qtdes();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

private:
    Ui::qtdes *ui;
};

#endif // QTDES_H
