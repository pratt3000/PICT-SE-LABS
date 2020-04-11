#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;
int x1,y1,x2,y2;
int thickness;
QImage image(431,351,QImage::Format_RGB888);
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


void MainWindow :: DDA(int x1,int y1, int x2, int y2){
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
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}
void MainWindow::on_pushButton_5_clicked(){
    //thicc line
    //error for slope = infinite
    for(int i=0;i<thickness/2;i++){
       DDA( x1, y1-i, x2, y2-i);
       DDA( x1, y1+i, x2, y2+i);
    }

}
void MainWindow::on_pushButton_4_clicked(){
    // DOTTED LINE
    //cout<<x1<<","<<y1<<","<<x2<<","<<y2<<endl;
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps/3;i++){
        image.setPixel(x,y,green);
        x=x+3*xinc;
        y=y+3*yinc;
        //cout<<x<<y<<endl;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_3_clicked(){
    //SOLID LINE
    //cout<<x1<<","<<y1<<","<<x2<<","<<y2<<endl;
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
        //cout<<x<<y<<endl;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_2_clicked(){
    //DASHED LINE
   // cout<<x1<<","<<y1<<","<<x2<<","<<y2<<endl;
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        if(i%5){
            image.setPixel(x,y,green);
        }
        x=x+xinc;
        y=y+yinc;

        //cout<<x<<y<<endl;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_clicked(){
    //DOT DASH LINE
    float dx,dy,steps,xinc,yinc;
    dx=x2-x1;
    dy=y2-y1;

    steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    xinc=dx/steps;
    yinc=dy/steps;

    float x=x1;
    float y=y1;

    for(int i=0;i<=steps;i++){
        if(i%5){
            image.setPixel(x,y,green);
        }
        else{
            image.setPixel(x+2*xinc,y+2*yinc,green);
            x = x + 4*xinc;
            y = y + 4*yinc;
        }
        x=x+xinc;
        y=y+yinc;

        //cout<<x<<y<<endl;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_textEdit_textChanged()
{
    QString str=ui->textEdit->toPlainText();
    x1=str.toInt();
}

void MainWindow::on_textEdit_2_textChanged()
{
    QString str=ui->textEdit_2->toPlainText();
    y1=str.toInt();
}

void MainWindow::on_textEdit_3_textChanged()
{
    QString str=ui->textEdit_3->toPlainText();
    x2=str.toInt();
}

void MainWindow::on_textEdit_4_textChanged()
{
    QString str=ui->textEdit_4->toPlainText();
    y2=str.toInt();
}

void MainWindow::on_textEdit_5_textChanged()
{
    QString str=ui->textEdit_5->toPlainText();
    thickness=str.toInt();
}
