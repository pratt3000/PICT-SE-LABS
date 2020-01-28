#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "QColorDialog"
 QImage img(500,500,QImage::Format_RGB888);
 QColor color;
 QRgb black = qRgb(0,0,0);
 QRgb blue = qRgb(0,0,255);
 QRgb green = qRgb(0,255,0);
 QRgb red = qRgb(255,0,0);
 int r=0,g=0,bl=0;
 int initialx, initialy;
 int restart = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vertices=0;
    start=true;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start==true){
                      int p = ev->pos().x();
                      int q = ev->pos().y();
                      a[vertices]=p-30;
                      b[vertices]=q+45;
                      if(restart == 0){
                          restart = 1;
                          initialx = p-30;
                          initialy = q+45;
                      }

                      if(ev->button()==Qt::RightButton){
                          dda(a[vertices],b[vertices],a[0],b[0]);
                           start=false;
                      }
                      else{
                          if(vertices>0){
                              dda(a[vertices],b[vertices],a[vertices-1],b[vertices-1]);
                          }
                      }
                 vertices++;

    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::dda(int x1, int y1, int x2, int y2){
    float dx,dy;
    float xinc,yinc;
    float len;
    dx=(x2-x1);
    dy=(y2-y1);
       if(abs(dx) >= abs(dy))
             len= abs(dx);
       else
            len= abs(dy);

       xinc=float( dx/len);
       yinc=float(dy/len);
       float x,y;
       x=x1;
       y=y1;
       int i=0;
       while(i<len){
        img.setPixel(x,y,color.rgb());
            x= x + xinc;
            y= y + yinc;
            i++;
       }
}

void MainWindow::on_pushButton_clicked(){
    color = QColorDialog::getColor();
}

void MainWindow::on_pushButton_2_clicked(){
    vertices=0;
    start=true;
    restart = 0;
}

void MainWindow::on_pushButton_3_clicked(){
    img.fill(black);
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->show();
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    r = value;
    color = qRgb(r,g,bl);
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
    g = value;
    color = qRgb(r,g,bl);
}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
    bl = value;
    color = qRgb(r,g,bl);
}

void MainWindow::on_pushButton_4_clicked()
{
    dda(initialx, initialy ,a[vertices-1],b[vertices-1]);
    vertices=0;
    start=true;
    restart = 0;
}
