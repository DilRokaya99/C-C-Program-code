#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
class bank{
     int bal;
     int acno;
     char actype[10];
     char name[20];
     public:
     void opbal();
     void deposit();
     void withdraw();
     void display();
};
void bank::opbal(){
    cout<<"enter your name:";
    cin>>name;
    cout<<"enter your account type:";
    cin>>actype;
    cout<<"enter your account nbr:";
    cin>>acno;
    cout<<"enter your balance:";
    cin>>bal;
}
void bank::deposit(){
    int deposit=0;
    cout<<"enter amount:";
    cin>>deposit;
    bal=deposit+bal;
    cout<<"deposit sucess"<<endl;
    cout<<"after deposit your total balnce:"<<bal;
}
void bank::withdraw(){
int withdraw;
cout<<"withdraw your balance:";
cin>>withdraw;
if(bal>withdraw){
    bal=bal-withdraw;
    cout<<"withdraw sucess"<<endl;
    cout<<"atfer withdraw your total balance:"<<bal;
}
else{
    cout<<"\n\tsorry not enough your balance";
}}
void bank::display(){
    cout<<endl<<endl;
    cout<<setw(50)<<"DETAIL:"<<endl;
    cout<<setw(50)<<"opbal:"<<bal<<endl;
    cout<<setw(50)<<"name:"<<name<<endl;
    cout<<setw(50)<<"acno:"<<acno<<endl;
    cout<<setw(50)<<"actype:"<<actype<<endl;
}
int main(){
    bank o1;
    int c;
    do{
        cout<<"\t\t\tdetail banking system program:"<<endl;
        cout<<"\t\t\t\tfollowing list:"<<endl;
        cout<<"1.to assign initial value:"<<endl;
        cout<<"2.deposit your amount:"<<endl;
        cout<<"3.withdraw your amount:"<<endl;
        cout<<"4.display all detail:"<<endl;
        cout<<"5.exit"<<endl;
    cout<<"choose any option:";
    cin>>c;
    switch(c){
        case 1:
        o1.opbal();
        break;
        case 2:
        o1.deposit();
        break;
        case 3:
        o1.withdraw();
        break;
        case 4:
        o1.display();
        break;
        case 5:
        goto end;
        default:
        cout<<"invalid choiice";
    }
    }while(1);
    end:
    getch();
    return 0;
}