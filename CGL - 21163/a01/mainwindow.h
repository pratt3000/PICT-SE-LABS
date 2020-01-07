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
    explicit MainWindow(QWidget *parent = 0);
    void bresenhamsAlgorithm(int,int,int,int);
    void ddaAlgorithm(int,int,int,int);
    ~MainWindow();

private slots:
    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
