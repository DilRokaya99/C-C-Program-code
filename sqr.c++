#include<iostream>
#include<conio.h>
using namespace std;
    int main(){
        int n;
        cout<<"enter the number ";
        cin>>n;
        if(100>n){
            cout<<"the squre number is:";
            for(int i=1;i<=n;i++){
                cout<<"\t"<<i*i;
            }
        }
        else{
            cout<<"invalid number";
        }
        return 0;
        getch();
}