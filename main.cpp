#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include <iterator>
#include <cstdlib>
#include<string>
#include<windows.h>

using namespace std;

string check(string file){
    string a,b;
    int x,c;
    vector<int>ms;
    ifstream fin(file);
    while(ios::out|ios::app){
        getline(fin,a);
        if(a[0]=='R'){
            for(int i=0;i<a.size();){
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
    for(int i=0;i<ms.size();i++){
        if(ms[i]<20)
            return "ok";
        else if(ms[i]>20 && ms[i]<60)
            return "minimum";
        else
            return "bad health";
    }
}

int main(){
    string file_name="result.txt";
    vector<char> buffer;
    string a="ping ";
    string b;
    string result;
    cin>>b;
    a+=b;
    while(true){
        system((a+">" + file_name).c_str()); 
        check(file_name);
        
    }
}
