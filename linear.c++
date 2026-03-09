#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int i,n,d;
    int a[100];
    cout<<"enter how many number do you want:";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"enter  the number to search:";
    cin>>d;
    for(i=0;i<n;i++){
        if(d==a[i]){
            cout<<"founded number";
            break;
        }
    }
        if(i==n){
            cout<<"not found";
          }
        return 0;
}