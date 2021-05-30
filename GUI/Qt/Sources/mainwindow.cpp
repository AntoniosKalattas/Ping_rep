#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<fstream>
#include<QMessageBox>
#include<Windows.h>

using namespace std;

int check(string file){
    string a,b;
    int x,c;
    vector<int>ms;
    ifstream fin(file);
    for(int i=0;i<5;i++){
        getline(fin,a);
        if(a[0]=='P'){
            if(a=="PING: transmit failed. General failure. ")
                return -1;
        }
        if(a[0]=='R'){
            if(a=="Request timed out.")
                return -1;
            for(unsigned int i=0;i<a.size();i++){
                if(a[i]=='t'){
                    x=i+4;
                    while(a[x]!='m'){
                        b+=a[x];
                        x++;
                    }
                c=stoi(b);
                ms.push_back(c);
                }
            }
        }
    }
    for(unsigned int i=0;i<ms.size();i++){
        if(ms[i]<20)
            return 0;
        else if(ms[i]>20 && ms[i]<60)
            return 1;
        else
            return 2;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked(){
    ofstream fout("traffic.txt");
    string file_name="result.txt";
    QString a="ping ";
    QString b = ui->lineEdit->text();
    string result;
    int j=0;
    a+=b;
    while(true){
    string x=a.toStdString();
        cout<<"ok";
      system((x+">" + file_name).c_str());
        //time_t now = time(0);
        //tm *ltm = localtime(&now);
        j=check(file_name);
        //Sleep(3000);
        if(j==0)
           ui->label_2->setText("ok");
        else if(j==1)
            ui->label_2->setText("minimum");
        else if(j==-1)
            QMessageBox::critical(this,"Error","request time out.Check the ip");
        else
            QMessageBox::critical(this,"bad","bad");
        //Sleep(30000);


  }
}
