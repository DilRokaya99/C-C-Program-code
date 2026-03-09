#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int n,i;
    cout<<"enter any number:";
    cin>>n;
    cout<<"=================================\n";
    for(i=1;i<11;i++){
        float mult=n*i;
        cout<<"|"<<i<<"|"<<"*"<<"|"<<n<<"|"<<"="<<mult<<"\n";
    }
    cout<<"==================================";
    return 0;
}