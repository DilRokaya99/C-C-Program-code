#include<iostream>
using namespace std;
int main()
{
    int i;
    float sal[10];
    cout<<"enter the sallery of 10 emp\n";
    for(i=1;i<=10;i++){
        cout<<"emp",i,":";
        cin>>sal[i];
    }
    float t=0;
    for(i=1;i<=10;i++){
        t=t+sal[i];
    }
    cout<<"the total sallry of emp are:",t;
    return 0;
}