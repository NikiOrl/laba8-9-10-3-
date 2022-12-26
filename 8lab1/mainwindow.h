#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_tabl_clicked();

    void on_pushButton_sl_clicked();

    void on_pushButton_min_clicked();

    void on_pushButton_puz_clicked();

    void on_pushButton_max_clicked();

    void on_pushButton_sred_clicked();

    void on_pushButton_ras_clicked();

    void on_lineEdit_kolvo_textChanged(const QString &arg1);

    void on_pushButton_gnom_clicked();

    void on_pushButton_bict_clicked();

    void on_pushButton_obezi_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
   bool IsSort(int *data, int count);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
