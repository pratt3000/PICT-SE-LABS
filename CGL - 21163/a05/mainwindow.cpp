#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "QtMath"
using namespace std;

/********Global Variables*******/
int side;
bool start=false;
QImage image(981,681,QImage::Format_RGB888);
QRgb black=qRgb(0,0,0);
QRgb white=qRgb(255,255,255);
int xc=490,yc=340;      //center:(490,340)

/******************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    image.fill(white);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
    ui->pushButton->setEnabled(false);

}

void MainWindow::bresenhamsLine(int x01, int y01, int x02, int y02)
{
    int dx=x02-x01;
    int dy=y02-y01;
    int x=x01;
    int y=y01;
    bool swapped=false;
    int sx=x02>x01?1:(-1);
    int sy=y02>y01?1:(-1);
    if(abs(dx)<abs(dy)){    //if slope>m
        swap(dx,dy);
        swap(x,y);
        swap(sx,sy);
        swapped=true;
    }
    int pk=2*abs(dy)-abs(dx);
    for(int i=0;i<abs(dx);i++){
        if(swapped)
            image.setPixel(y,x,black);
        else
            image.setPixel(x,y,black);
        cout<<x<<","<<y<<"\n";
        x+=sx;
        if(pk<0)
            pk=pk+2*abs(dy);
        else{
            y+=sy;
            pk=pk+2*abs(dy)-2*abs(dx);
        }
    }
    //ui->label->setPixmap(QPixmap::fromImage(image));
    //ui->label->show();
}

void MainWindow::floodFill(int x, int y)
{
    QRgb currentColor=image.pixel(x,y);
    if (x < 0 || x >= 981 || y < 0 || y >= 681)
        return;
    if(currentColor==black)
        return;
    image.setPixel(x,y,black);
    floodFill(x+1,y);
    floodFill(x-1,y);
    floodFill(x,y+1);
    floodFill(x,y-1);
}

void MainWindow::drawGrid()
{
    float root2=sqrt(2);
    float delta=side/(4*root2);
    int x01,y01,x02,y02;
    for(int i=0;i<=4;i++){
        x01=xc-i*delta;
        y01=yc-side/root2+i*delta;
        x02=xc+side/root2-i*delta;
        y02=yc+i*delta;
        bresenhamsLine(x01,y01,x02,y02);
        bresenhamsLine(x02,y02,x01,y01);
    }
    for(int i=0;i<=4;i++){
        x02=xc+i*delta;
        y02=yc-side/root2+i*delta;
        x01=xc-side/root2+i*delta;
        y01=yc+i*delta;
        bresenhamsLine(x01,y01,x02,y02);
        bresenhamsLine(x02,y02,x01,y01);
    }
}

void MainWindow::fillGrid()
{
    float root2=sqrt(2);
    float delta=side/(4*root2);
    floodFill(xc,yc-delta);
    floodFill(xc,yc-3*delta);
    floodFill(xc,yc+delta);
    floodFill(xc,yc+3*delta);
    floodFill(xc-2*delta,yc-delta);
    floodFill(xc-2*delta,yc+delta);
    floodFill(xc+2*delta,yc-delta);
    floodFill(xc+2*delta,yc+delta);
}

void MainWindow::on_textEdit_textChanged()
{
    QString str=ui->textEdit->toPlainText();
    side=str.toInt();
    start=true;
    ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    on_pushButton_2_clicked();
    drawGrid();
    fillGrid();
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    image.fill(white);
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
