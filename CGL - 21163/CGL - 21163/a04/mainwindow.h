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
    ~MainWindow();
    void mousePressEvent(QMouseEvent *ev);

private slots:
     void dda(int,int,int,int);
     void on_pushButton_clicked();
     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

    // void on_radioButton_toggled(bool checked);

     void on_verticalSlider_valueChanged(int value);

     void on_verticalSlider_2_valueChanged(int value);

     void on_verticalSlider_3_valueChanged(int value);

     void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    int a[20],b[20];
    int x1,y1,x2,y2,vertices;
    bool start;
};

#endif // MAINWINDOW_H
