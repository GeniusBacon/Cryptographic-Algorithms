#ifndef QTRAILFENCE_H
#define QTRAILFENCE_H

#include <QDialog>

namespace Ui {
class qtrailfence;
}

class qtrailfence : public QDialog
{
    Q_OBJECT

public:
    explicit qtrailfence(QWidget *parent = nullptr);
    ~qtrailfence();

private slots:
    void on_EncryptPushButton_clicked();

    void on_DecryptPushButton_clicked();

    void on_AnalyzePushButton_clicked();

private:
    Ui::qtrailfence *ui;
};

#endif // QTRAILFENCE_H
