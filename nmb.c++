#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int i,j,n;
    cout<<"enter eny number:";
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<" "<<j;
        }
        cout<<"\n";
    }
    return 0;
}