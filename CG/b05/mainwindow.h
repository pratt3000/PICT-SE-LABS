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
    void drawGrid();
    void drawStroke(int);
    void hilbertCurve(int,int);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int direction;
    int level;
    int strokeSize;
    QPoint *current;
};

#endif // MAINWINDOW_H
