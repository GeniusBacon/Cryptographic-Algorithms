#ifndef QTCAESAR_H
#define QTCAESAR_H

#include <QDialog>
#include <QPushButton>
#include <QString>


namespace Ui {
class QtCaesar;
}

class QtCaesar : public QDialog
{
    Q_OBJECT

public:
    explicit QtCaesar(QWidget *parent = nullptr);
    ~QtCaesar();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::QtCaesar *ui;
};

#endif // QTCAESAR_H
