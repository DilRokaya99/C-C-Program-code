#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    float e[6];
    int i;
    cout<<"enter the 5 employees salary:\n";
    for(i=1;i<5;i++){
      cin>>e[i];
      cout<<i<<"."<<"the employe salry is:"<<e[i]<<"\n";
    }
    float totalsal=0;
    for(i=1;i<5;i++){
        totalsal+=e[i];
    }
    cout<<"\nall employes total salary are:"<<totalsal;
    return 0;

}