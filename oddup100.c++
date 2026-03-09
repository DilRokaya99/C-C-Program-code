#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number up to 100:";
    cin>>n;
    if(100>n){
        int sum=0;
        for(int i=99;i>=1;i=i-2){
            cout<<"\t"<<i;
            sum+=i;
        }
        cout<<"the sum is:                                            "<<sum;
    }
    else{
        cout<<"this number is more than 100. \nSo please enter the numebr less than 100";
    }
    return 0;
    getch();
}