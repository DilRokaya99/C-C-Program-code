#include<iostream>
#include<conio.h>
using namespace std;
    int main(){
        int sel,cost,amount;
        cout<<"enter the cost price:";
        cin>>cost;
        cout<<"enter the sales price:";
        cin>>sel;
        if(cost>sel){
            amount=cost-sel;
            cout<<"your loss amount is:"<<amount;
        }
        else if(sel>cost){
            amount=sel-cost;
            cout<<"your profit is:"<<amount;
        }
        else{
            cout<<"your amount is neither profit nor loss";
        }
        return 0;
        getch();
    }
