#include <iostream>
#include "AuthSystem.h"
#include "MailSystem.h"
using namespace std;
int main(){
    AuthSystem auth;
    MailSystem mail;
    int choice; string current="";
    while(true){
        cout<<"1.Register\n2.Login\n3.Exit\nChoice: "; cin>>choice;
        if(choice==1) auth.registerUser();
        else if(choice==2){ current=auth.login(); if(current!="") break; }
        else return 0;
    }
    while(true){
        cout<<"\n1.Send\n2.Inbox\n3.Delete\n4.Logout\nChoice: "; cin>>choice; cin.ignore();
        if(choice==1) mail.sendEmail(current);
        else if(choice==2) mail.showInbox(current);
        else if(choice==3) mail.deleteEmail(current);
        else break;
    }
}
