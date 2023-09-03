#ifndef QTHILL_H
#define QTHILL_H

#include <QDialog>

namespace Ui {
class qtHill;
}

class qtHill : public QDialog
{
    Q_OBJECT

public:
    explicit qtHill(QWidget *parent = nullptr);
    ~qtHill();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_EncryptPushButton_clicked();


    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::qtHill *ui;
};

#endif // QTHILL_H
