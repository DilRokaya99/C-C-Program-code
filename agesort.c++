#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int a[100];
    int i,j,n,t; 
    cout<<"enter how many student age:";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"enter"<<i<<"student age:";
        cin>>a[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(a[i]<a[j]){
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    cout<<"age after sorting in ascending order are:\n";
    for(i=1;i<=n;i++){
        cout<<a[i]<<"\n";
    }
   getch();
    }