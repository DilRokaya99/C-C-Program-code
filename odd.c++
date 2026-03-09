#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int n;
    cout<<"enter any odd munber:";
    cin>>n;
    for(int i=1;i<=n;i+1){
        i=i+2;
        cout<<i<<",";
    }
    return 0;
}