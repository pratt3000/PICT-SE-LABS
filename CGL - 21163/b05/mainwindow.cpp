#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
#include "iostream"
using namespace std;
 
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

/***********Global Variables**********/
QRgb black=qRgb(0,0,0);
QRgb red=qRgb(255,0,0);
QRgb green=qRgb(0,255,0);
QRgb blue=qRgb(0,0,255);
QRgb white=qRgb(255,255,255);

QImage image(941,691,QImage::Format_RGB888);

int startX,startY;

/************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image.fill(white);
    level=1;
    direction=DOWN;
    strokeSize=ceil(670/pow(2,level));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::drawGrid()
{
    int step=ceil(670/pow(2,level));
    int side=step*pow(2,level);

    for(int i=0;i<=side;i+=step){
        for(int j=0;j<=side;j+=4){
         image.setPixel(135+j,i+10,black);
         image.setPixel(135+i,j+10,black);
        }
    }

    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

    /*
        (135,10)                (805,10)
            *-----------------------*
            |                       |
            |                       |
            |                       |
            |                       |
            |                       |
            *-----------------------*
        (135,680)               (805,680)
     */
}

void MainWindow::drawStroke(int direction)
{
    int x=current->x();
    int y=current->y();

    switch (direction) {
    case UP:
        for(int i=0;i<strokeSize;i++)
            image.setPixel(x,y--,blue);
        break;
    case LEFT:
        for(int i=0;i<strokeSize;i++)
            image.setPixel(x--,y,blue);
        break;
    case DOWN:
        for(int i=0;i<strokeSize;i++)
            image.setPixel(x,y++,blue);
        break;
    case RIGHT:
        for(int i=0;i<strokeSize;i++)
            image.setPixel(x++,y,blue);
        break;
    default:
        break;
    }
    current=new QPoint(x,y);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();

}

void MainWindow::hilbertCurve(int level, int direction=DOWN)
{
    if(level<=1){
        switch (direction) {
        case UP:
            drawStroke(DOWN);
            drawStroke(RIGHT);
            drawStroke(UP);
            break;
        case LEFT:
            drawStroke(RIGHT);
            drawStroke(DOWN);
            drawStroke(LEFT);
            break;
        case DOWN:
            drawStroke(UP);
            drawStroke(LEFT);
            drawStroke(DOWN);
            break;
        case RIGHT:
            drawStroke(LEFT);
            drawStroke(UP);
            drawStroke(RIGHT);
            break;
        }
        return;
    }
    switch (direction) {
    case UP:
        hilbertCurve(level-1,LEFT);
        drawStroke(DOWN);
        hilbertCurve(level-1,UP);
        drawStroke(RIGHT);
        hilbertCurve(level-1,UP);
        drawStroke(UP);
        hilbertCurve(level-1,RIGHT);
        break;
    case LEFT:
        hilbertCurve(level-1,UP);
        drawStroke(RIGHT);
        hilbertCurve(level-1,LEFT);
        drawStroke(DOWN);
        hilbertCurve(level-1,LEFT);
        drawStroke(LEFT);
        hilbertCurve(level-1,DOWN);
        break;
    case DOWN:
        hilbertCurve(level-1,RIGHT);
        drawStroke(UP);
        hilbertCurve(level-1,DOWN);
        drawStroke(LEFT);
        hilbertCurve(level-1,DOWN);
        drawStroke(DOWN);
        hilbertCurve(level-1,LEFT);
        break;
    case RIGHT:
        hilbertCurve(level-1,DOWN);
        drawStroke(LEFT);
        hilbertCurve(level-1,RIGHT);
        drawStroke(UP);
        hilbertCurve(level-1,RIGHT);
        drawStroke(RIGHT);
        hilbertCurve(level-1,UP);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    level=arg1.toInt();
    strokeSize=ceil(670/pow(2,level));
//    cout<<level<<"\n";
}

void MainWindow::on_radioButton_clicked()
{
    direction=UP;
//    cout<<direction<<"\n";
}

void MainWindow::on_radioButton_2_clicked()
{
    direction=LEFT;
//    cout<<direction<<"\n";
}

void MainWindow::on_radioButton_3_clicked()
{
    direction=DOWN;
//    cout<<direction<<"\n";
}

void MainWindow::on_radioButton_4_clicked()
{
    direction=RIGHT;
//    cout<<direction<<"\n";
}

void MainWindow::on_pushButton_clicked()
{
    on_pushButton_2_clicked();      //clear

    drawGrid();
    if(direction==DOWN||direction==RIGHT){
        startX=805-(strokeSize/2);
        startY=680-(strokeSize/2);
        current=new QPoint(startX,startY);
    }
    else{
        startX=135+(strokeSize/2);
        startY=10+(strokeSize/2);
        current=new QPoint(startX,startY);
    }
    hilbertCurve(level,direction);
}

void MainWindow::on_pushButton_2_clicked()      //clear
{
    image.fill(white);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
