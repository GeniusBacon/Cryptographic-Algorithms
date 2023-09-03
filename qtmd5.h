#ifndef QTMD5_H
#define QTMD5_H

#include <QDialog>

namespace Ui {
class qtmd5;
}

class qtmd5 : public QDialog
{
    Q_OBJECT

public:
    explicit qtmd5(QWidget *parent = nullptr);
    ~qtmd5();

private slots:
    void on_GetHashButton_clicked();

private:
    Ui::qtmd5 *ui;
};

#endif // QTMD5_H
