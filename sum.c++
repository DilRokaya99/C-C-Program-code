#include <iostream>
#include <conio.h>
using namespace std;
  int main(){
    int n;
    float sum;
    cout<<"enter any number:";
    cin>>n;
    for(int i=1;i<=n;i++){
     sum+=i;
    }
    cout<<"the sum number are:"<<sum;
}