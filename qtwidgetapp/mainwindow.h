#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_reset_clicked();

private:
    Ui::MainWindow *ui;
    static std::string zusan[];
    static void list_to_string(list<string>&,string&);
    static void filter_by_danma(list<string>&,const string&);
    static void filter_by_hewei(list<string>&,const string&);
    static void filter_by_kuadu(list<string>&,const string&);
    static void filter_by_shama(list<string>&,const string&);

};

#endif // MAINWINDOW_H
