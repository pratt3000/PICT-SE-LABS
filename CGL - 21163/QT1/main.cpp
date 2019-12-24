#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
#include<QtGui>
#include<QImage>
#include<QLabel>


int main(int argc, char *argv[])
{
QApplication app(argc, argv);
MainWindow window;
window.resize(500, 300); //resize draws window with width and height
window.setWindowTitle("Simple example"); //add title on window
window.show(); //shows the window


return app.exec();

}
