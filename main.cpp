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

int main(){
    string file_name="result.txt";
    vector<char> buffer;
    string a="ping ";
    string b;
    string result;
    cin>>b;
    a+=b;
    while(true)
        system((a+">" + file_name).c_str()); 
}
