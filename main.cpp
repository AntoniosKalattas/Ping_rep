#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include <iterator>
#include <cstdlib>
#include<string>
#include<ctime>


#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

using namespace std;

int check(string file){
    string a,b;
    int x,c;
    vector<int>ms;
    ifstream fin(file);
    while(!fin.eof()){
        getline(fin,a);
        if(a[0]=='R'){
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

int main(){
    ofstream fout("traffic.txt");
    string file_name="result.txt";
    vector<char> buffer;
    string a="ping ";
    string b;
    string result;
    cin>>b;
    a+=b;
    int j;
    while(true){
        system((a+">" + file_name).c_str());
        time_t now = time(0);
        tm *ltm = localtime(&now);
        j=check(file_name);
        if(j==0)
            cout<<"["<<ltm->tm_hour<<":"<<30+ltm->tm_min<<":"<<ltm->tm_sec<<"] "<<GREEN<<"OK!"<<RESET<<endl;
        else if(j==1)
            cout<<"["<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"] "<<YELLOW<<"MINIMUM"<<RESET<<endl;
        else{
            cout<<"["<<ltm->tm_hour<<":"<<30+ltm->tm_min<<":"<<ltm->tm_sec<<"] "<<RED<<"NOT OK"<<RESET<<endl;
            fout<<"["<<ltm->tm_hour<<":"<<30+ltm->tm_min<<":"<<ltm->tm_sec<<"] "<<RED<<"NOT OK"<<RESET<<endl;
        }
    }
}
