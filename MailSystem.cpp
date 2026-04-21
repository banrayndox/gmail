#include "MailSystem.h"
#include "SpamDetector.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void MailSystem::sendEmail(const string& sender){
 string r,s,b; cout<<"Receiver: ";getline(cin,r); cout<<"Subject: ";getline(cin,s); cout<<"Body: ";getline(cin,b);
 ifstream in("emails.txt"); string line; int id=1; while(getline(in,line)) id++;
 bool spam=SpamDetector::isSpam(s+" "+b);
 ofstream f("emails.txt",ios::app);
 f<<id<<","<<sender<<","<<r<<","<<s<<","<<b<<","<<(spam?"spam":"inbox")<<"\n";
 cout<<(spam?"Sent (Marked spam)\n":"Sent\n");
}
void MailSystem::showInbox(const string& user){
 ifstream f("emails.txt"); string line;
 while(getline(f,line)){
   stringstream ss(line); vector<string> v; string x;
   while(getline(ss,x,',')) v.push_back(x);
   if(v.size()>=6 && v[2]==user){
     cout<<"ID:"<<v[0]<<" From:"<<v[1]<<" Subject:"<<v[3]<<" Status:"<<v[5]<<"\n";
   }
 }
}
void MailSystem::deleteEmail(const string& user){
 int del; cout<<"Delete ID: ";cin>>del; cin.ignore();
 ifstream f("emails.txt"); ofstream t("temp.txt"); string line;
 while(getline(f,line)){
   stringstream ss(line); vector<string> v; string x;
   while(getline(ss,x,',')) v.push_back(x);
   if(v.size()>=6 && !(stoi(v[0])==del && v[2]==user)) t<<line<<"\n";
 }
 f.close(); t.close(); remove("emails.txt"); rename("temp.txt","emails.txt");
 cout<<"Deleted\n";
}
