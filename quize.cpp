#include<iostream>
#include<conio.h>
using namespace std;
void quize (){
    int c;
    cout<<"QN.1:where is the mountain averast in the world:";
    cout<<"\n1.nepal\n2.india\n3.bhutan\n4.pakistan\n";
    cin>>c;
    if(c==1){
        cout<<"\ncorrect answer";
    }
    else{
        cout<<"\nwrong answer";
    }
    cout<<"\nQN.2:what is the main brain of the computer:";
    cout<<"\n1.dvd\n2.hdd\n3.cpu\n4.monitor\n";
    cin>>c;
    if(c==3){
        cout<<"correct answer";
    }
    else{
    cout<<"wrong answer";
    }
}
int main (){
    int ch;
    char h;
    cout<<"enter any key:";
    cin>>h;
    cout<<"\n...WELCOME TO OUR QUIZE...";
    cout<<"\n\n\n";
    do{
    cout<<"\nDO YOU WANT TO QUIZE COMPETETION\n";
    cout<<"1.YES\n2.NO\n";
    cin>>ch;
    switch(ch){
        case 1:
        quize();
        break;
        case 2:
        cout<<"PUTI KHA";
        goto end;
        default:
        cout<<"invalid choice\n";
        cout<<"\nplease try agian";
    }
    }while(1);
     end:
    return 0;
}