#include "AuthSystem.h"
#include <iostream>
#include <fstream>
using namespace std;
void AuthSystem::registerUser(){
 string e,p; cout<<"Email: ";cin>>e; cout<<"Password: ";cin>>p;
 ofstream f("users.txt",ios::app); f<<e<<","<<p<<"\n";
 cout<<"Registered\n";
}
string AuthSystem::login(){
 string e,p,line; cout<<"Email: ";cin>>e; cout<<"Password: ";cin>>p;
 ifstream f("users.txt");
 while(getline(f,line)){
   auto pos=line.find(',');
   if(line.substr(0,pos)==e && line.substr(pos+1)==p){ cout<<"Login success\n"; return e; }
 }
 cout<<"Invalid\n"; return "";
}
