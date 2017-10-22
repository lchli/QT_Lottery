#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <list>
#include <iostream>
#include <sstream>
using namespace std;

string MainWindow::zusan[]={"122","689"};


void MainWindow::list_to_string(list<string>& zs,string& ret){

    list<string>::iterator it;
    for(it=zs.begin();it!=zs.end();it++){
        ret+=*it+",";
    }

    ret.erase(ret.end()-1,ret.end());
}

void MainWindow::filter_by_danma(list<string>& zs,const string& dm){
    list<string>::iterator it=zs.begin();
    while(it!=zs.end()){
        bool valid=false;

        for(string::size_type i=0;i<dm.size();i++){
            if(it->find(dm[i])!=string::npos){
                valid=true;
                break;
            }
        }

        if(!valid){
            cout<<"erase:"<<*it<<endl;
            it=zs.erase(it);

        }else{
            ++it;
        }
    }
}


void MainWindow::filter_by_shama(list<string>& zs,const string& dm){
    list<string>::iterator it=zs.begin();
    while(it!=zs.end()){
        bool valid=true;

        for(string::size_type i=0;i<dm.size();i++){
            if(it->find(dm[i])!=string::npos){
                valid=false;
                break;
            }
        }

        if(!valid){
            cout<<"erase:"<<*it<<endl;
            it=zs.erase(it);

        }else{
            ++it;
        }
    }
}

void MainWindow::filter_by_hewei(list<string>& zs,const string& dm){
    list<string>::iterator it=zs.begin();
    while(it!=zs.end()){
        string& item=*it;
        int hezhi=0;
        for(string::size_type j=0;j<item.size();j++){
            int num=item[j]-'0';
            hezhi+=num;
        }
        int hewei=hezhi%10;
        cout<<"item:"<<item<<",hewei:"<<hewei<<endl;

        char hewei_str;
        stringstream ss;
        ss<<hewei;
        ss>>hewei_str;

        if(dm.find(hewei_str)==string::npos){
            cout<<"erase:"<<item<<endl;
            it=zs.erase(it);

        }else{
            ++it;
        }
    }

}

void MainWindow::filter_by_kuadu(list<string>& zs,const string& dm){
    list<string>::iterator it=zs.begin();
    while(it!=zs.end()){
        string& item=*it;

        int min=item[0]-'0';
        int max=item[0]-'0';

        for(string::size_type j=0;j<item.size();j++){
            int num=item[j]-'0';
            if(num>max){
                max=num;
            }else if(num<min){
                min=num;
            }
        }

        int kuadu=max-min;

        cout<<"item:"<<item<<",kuadu:"<<kuadu<<endl;

        char kuadu_str;
        stringstream ss;
        ss<<kuadu;
        ss>>kuadu_str;

        if(dm.find(kuadu_str)==string::npos){
            cout<<"erase:"<<item<<endl;
            it=zs.erase(it);

        }else{
            ++it;
        }
    }
}


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
    string dm=ui->lineEdit->text().toStdString();
    string hewei=ui->lineEdit_hewei->text().toStdString();
    string kuadu=ui->lineEdit_kuadu->text().toStdString();
    string shama=ui->lineEdit_shama->text().toStdString();


    list<string> zs(zusan, zusan+sizeof(zusan)/sizeof(zusan[0]));

    if(!dm.empty()){
        filter_by_danma(zs,dm);
    }

    if(!hewei.empty()){
        filter_by_hewei(zs,hewei);
    }

    if(!kuadu.empty()){
        filter_by_kuadu(zs,kuadu);
    }

    if(!shama.empty()){
        filter_by_shama(zs,shama);
    }


    string ret;
    if(!zs.empty()){
        list_to_string(zs,ret);
    }


    ui->textEdit->setText(QString::fromStdString(ret));
}

void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_hewei->setText("");
    ui->lineEdit_kuadu->setText("");
    ui->lineEdit_shama->setText("");
    ui->textEdit->setText("");

}