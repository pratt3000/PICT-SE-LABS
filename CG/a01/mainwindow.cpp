#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
int length,breadth;
QImage image(891,601,QImage::Format_RGB888);
QRgb green=qRgb(0,255,0);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textEdit_textChanged()
{
    QString str=ui->textEdit->toPlainText();
    length=str.toInt();
}

void MainWindow::on_textEdit_2_textChanged()
{
    QString str=ui->textEdit_2->toPlainText();
    breadth=str.toInt();
}
void MainWindow::bresenhamsAlgorithm(int x1,int y1,int x2,int y2){
    int dx=x2-x1;
    int dy=y2-y1;
    int x=x1;
    int y=y1;
    if(abs(dx)>abs(dy)){
        int pk=2*abs(dy)-abs(dx);
//        int pk=2*dy-dx;
        for(int i=0;i<abs(dx);i++){
            image.setPixel(x,y,green);
            x++;
            if(pk<0)
                pk=pk+2*abs(dy);
//                pk=pk+2*dy;
            else{
                y++;
                pk=pk+2*abs(dy)-2*abs(dx);
//                pk=pk+2*dy-2*dx;
            }
        }
    }
    else{
        int pk=2*abs(dx)-abs(dy);
//        int pk=2*dx-dy;
        for(int i=0;i<abs(dy);i++){
            image.setPixel(x,y,green);
            y++;
            if(pk<0)
                pk=pk+2*abs(dx);
//                pk=pk+2*dx;
            else{
                x++;
                pk=pk+2*abs(dx)-2*abs(dy);
//                pk=pk+2*dx-2*dy;
            }
        }
    }
    return;
}
void MainWindow::ddaAlgorithm(int x1,int y1,int x2,int y2){
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
void MainWindow::on_pushButton_clicked()
{
    int x0=20,y0=20;
    int x1=20+length,y1=20;
    int x2=20+length,y2=20+breadth;
    int x3=20,y3=20+breadth;
    bresenhamsAlgorithm(x0,y0,x1,y1);
    bresenhamsAlgorithm(x1,y1,x2,y2);
    bresenhamsAlgorithm(x3,y3,x2,y2);
    bresenhamsAlgorithm(x0,x0,x3,y3);

    int x4=(x0+x1)/2, y4=(y0+y1)/2;
    int x5=(x1+x2)/2, y5=(y1+y2)/2;
    int x6=(x2+x3)/2, y6=(y2+y3)/2;
    int x7=(x3+x0)/2, y7=(y3+y0)/2;
    ddaAlgorithm(x4,y4,x5,y5);
    ddaAlgorithm(x5,y5,x6,y6);
    ddaAlgorithm(x6,y6,x7,y7);
    ddaAlgorithm(x7,y7,x4,y4);

    int x8=(x4+x5)/2, y8=(y4+y5)/2;
    int x9=(x5+x6)/2, y9=(y5+y6)/2;
    int x10=(x6+x7)/2,y10=(y6+y7)/2;
    int x11=(x7+x4)/2,y11=(y7+y4)/2;
    bresenhamsAlgorithm(x8,y8,x9,y9);
    bresenhamsAlgorithm(x10,y10,x9,y9);
    bresenhamsAlgorithm(x11,y11,x10,y10);
    bresenhamsAlgorithm(x11,y11,x8,y8);

    ui->label_3->setPixmap(QPixmap::fromImage(image));
    ui->label_3->show();
}
