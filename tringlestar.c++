#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int i,j,k;
    for(i=1;i<20;i++){
        for(j=20;j>=i;j--){
            cout<<" ";
        }
            for(k=1;k<=i;k++){
                cout<<"$ ";
            }
                cout<<"\n";
            }
    return 0;
}