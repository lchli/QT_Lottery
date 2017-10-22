#include "mainwindow.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    using namespace std;
    cout<<"window will be show=="<<endl;

    w.show();

    return a.exec();
}
