#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int a[100]={3,2,1,8,9,5};
    int pos,num,i;
    cout<<"that enter the position:";
    cin>>num;
    for(i=7;i>=pos;i--){
        a[i+1]=a[i];
        a[pos]=num;
    }
        cout<<"new array:";
        for(i=0;i<6;i=i+1){
            cout<<a[i];
            cout<<" ";
        }
        getch();
        return 0;
}