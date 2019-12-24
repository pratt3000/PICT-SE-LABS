#include "mainwindow.h"
#include "ui_mainwindow.h"
QImage image(300, 300, QImage::Format_RGB888);
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

void MainWindow::on_pushButton_clicked()
{
    QImage image(300, 300, QImage::Format_RGB888);
    QRgb value, value1,value2;
    value = qRgb(255,255,255);
    value1 = qRgb(0,255,0);
    value2 = qRgb(0,0,255);
    //set color of pixel as green
    for(int i=0;i<100;i++){
        image.setPixel(50,50+i+50,value);
        image.setPixel(250,50+i+50,value);//draws pixel with value
        image.setPixel(50+2*i,50+50,value);
        image.setPixel(50+2*i+1,50+50,value);
        image.setPixel(50+2*i,150+50,value);
        image.setPixel(50+2*i+1,150+50,value);

        image.setPixel(100+i, 75+50,value1);
        image.setPixel(100+i, 125+50,value1);

    }
    for(int i=0;i<50;i++){
        image.setPixel(100, 75+i+50,value1);
        image.setPixel(200, 75+i+50,value1);
    }
    for(int i=150; i<250;i++){
        value = value2;
        image.setPixel(i,((i-50)/2)+50,value);
        image.setPixel(300-i,((i-50)/2)+50,value);
        image.setPixel(i-100,((i-50)/2)+50+50,value);
        image.setPixel(300-i+100,((i-50)/2)+50+50,value);
    }
    //position.
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString s;
    float x1,y1,x2,y2;
    s = ui->plainTextEdit->toPlainText();
    x1 = s.toFloat();
    s = ui->plainTextEdit_2->toPlainText();
    y1 = s.toFloat();
    s = ui->plainTextEdit_3->toPlainText();
    x2 = s.toFloat();
    s = ui->plainTextEdit_4->toPlainText();
    y2 = s.toFloat();
    bresen(x1, y1, x2, y2);
    ui->label_2->setPixmap(QPixmap::fromImage(image));
    ui->label_2->show();
}
void MainWindow::bresen(int x1,int y1,int x2,int y2){
    QRgb value1;
    //QRgb value2;
    //QRgb value;
    //value = qRgb(255,255,255);
    value1 = qRgb(0,255,0);
    //value2 = qRgb(0,0,255);
    float dy,dx, p0, p1;
    dy = y2 - y1;
    dx = x2 - x1;
    if(dy/dx <1){
        p0 = 2*dy - dx;
        for(int x=x1 ; x<dx ; x++){
            if(p0 < 0)
                p1 = p0 + 2*dy;
            else if(p0 >= 0)
                p1 = p0 + 2*dy - 2*dx;
            if(p1 >= 0)
                y1++;
            image.setPixel( x , y1 ,value1);
        }
    }
    // error : works in only 0 to 45 degrees
    else{
        p0 = 2*dx - dy;
        for(int y=y1 ; y<dy ; y++){
            if(p0 < 0)
                p1 = p0 + 2*dx;
            else if(p0 >= 0)
                p1 = p0 + 2*dx - 2*dy;
            if(p1 >= 0)
                x1++;
            image.setPixel( x1 , y ,value1);
        }
    }
    //image.setPixel( x1 , y1 ,value1);

}
