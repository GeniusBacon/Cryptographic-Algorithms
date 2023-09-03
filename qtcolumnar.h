#ifndef QTCOLUMNAR_H
#define QTCOLUMNAR_H

#include <QDialog>

namespace Ui {
class qtcolumnar;
}

class qtcolumnar : public QDialog
{
    Q_OBJECT

public:
    explicit qtcolumnar(QWidget *parent = nullptr);
    ~qtcolumnar();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();


    void on_AnalyzePushButton_clicked();

private:
    Ui::qtcolumnar *ui;
};

#endif // QTCOLUMNAR_H
