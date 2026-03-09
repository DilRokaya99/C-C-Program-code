#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int n,i;
    cout<<"enter any number:";
    cin>>n;
    if(n>0){
        int f=1;
        for(i=n;i>=1;i--){
            f=f*i;
        }
        cout<<"the factorial number is:"<<f;
    }
    else{
    cout<<"this is not positive number";
    }
 return 0;
}