#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
int radius;
int xc=260,yc=190;
QImage image(521,381,QImage::Format_RGB888);
QRgb green=qRgb(0,255,0);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::bresenhamCircle(int radius){
    int x=0,y=radius;
    int d=3-2*radius;
    drawCircle(x,y);
    while(y>=x){
        x++;
        if(d>0){
            y--;
            d=d+4*(x-y)+10;
        }
        else
            d=d+4*x+6;
       drawCircle(x,y);
    }
}
void MainWindow::DDACircle(int r){
    float xc1,xc2,yc1,yc2,eps,sx,sy;
    int val,i;
     xc1=r;
     yc1=0;
     sx=xc1;
     sy=yc1;
     i=0;
     do{
         val=pow(2,i);
         i++;
         }while(val<r);
     eps = 1/pow(2,i-1);
     do{
         xc2 = xc1 + yc1*eps;
         yc2 = yc1 - eps*xc2;
         image.setPixel(xc+xc2,yc-yc2,green);
         xc1=xc2;
         yc1=yc2;
        }while((yc1-sy)<eps || (sx-xc1)>eps);
     //image.setPixel(xc,yc,green);
     ui->label->setPixmap(QPixmap::fromImage(image));
     ui->label->show();
}
void MainWindow::DDA_line(int x1,int y1,int x2,int y2){
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        image.setPixel(x,y,green);
        x=x+xinc;
        y=y+yinc;
    }
}
void MainWindow::drawCircle(int x,int y){
    image.setPixel(xc+x,yc+y,green);
    image.setPixel(xc-x,yc+y,green);
    image.setPixel(xc+x,yc-y,green);
    image.setPixel(xc-x,yc-y,green);
    image.setPixel(xc+y,yc+x,green);
    image.setPixel(xc-y,yc+x,green);
    image.setPixel(xc+y,yc-x,green);
    image.setPixel(xc-y,yc-x,green);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_textEdit_textChanged()
{
    QString str=ui->textEdit->toPlainText();
    radius=str.toInt();
}
void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x2,y2,x3,y3;
    x1 = xc;
    y1 = yc - 2 * radius;
    x2 = xc + 1.732 * radius;
    y2 = yc + radius;
    x3 = xc - 1.732 * radius;
    y3 = yc + radius;
    DDA_line(x1, y1, x2, y2);
    DDA_line(x1, y1, x3, y3);
    DDA_line(x3, y3, x2, y2);
    bresenhamCircle(radius);
    DDACircle(radius*2);
}
