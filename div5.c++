#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int n1,n2;
    cout<<"enter one number:";
    cin>>n1;
    cout<<"enter another number:";
    cin>>n2;
    if(n1%5==0 && n2%7==0){
        cout<<"exactly divisible by 5 or 7";
    }

    else{
        cout<<"not exactly divisible by 5 or 7";
    }
    return 0;
}