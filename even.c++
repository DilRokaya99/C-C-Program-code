#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int n;
    cout<<"enter any even number:";
    cin>>n;
    for(int i=2;i<=n;i+2){  
        i+=2;
        cout<<i<<",";
    }
    return 0;
}