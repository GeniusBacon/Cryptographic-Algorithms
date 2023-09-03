#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtcaesar.h"
#include "qtcolumnar.h"
#include "qthill.h"
#include "qtmonoalphabetic.h"
#include "qtplayfair.h"
#include "qtrailfence.h"
#include "qtvigenereautokey.h"
#include "qtvigenererepeatingkey.h"
#include "qtdes.h"
#include "qtaes.h"
#include "qtrsa.h"
#include "qtmd5.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CaesarButton_clicked();

    void on_HillPushButton_clicked();

    void on_ColumnarButton_clicked();

    void on_MonoalphabeticButton_clicked();

    void on_playfairButton_clicked();

    void on_RailfenceButton_clicked();

    void on_VigenereRepeatingKeyButton_clicked();

    void on_VigenereAutoKeyButton_clicked();

    void on_DesButton_clicked();

    void on_AesButton_clicked();

    void on_RsaButton_clicked();

    void on_Md5Button_clicked();

private:
    Ui::MainWindow *ui;
    QtCaesar *c;
    qtcolumnar *co;
    qtHill *h;
    qtmonoalphabetic *m;
    qtplayfair *p;
    qtrailfence *r;
    qtvigenereAutoKey *va;
    qtvigenereRepeatingKey *vr;
    qtdes *d;
    qtaes *a;
    qtrsa *rs;
    qtmd5 *md;


};
#endif // MAINWINDOW_H
