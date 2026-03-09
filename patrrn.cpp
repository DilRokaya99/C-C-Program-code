#include<iostream>
using namespace std;
int main(){
    char text[]="WELCOME";
    int i,j;
    cout<<"the required pattern is:";
    cout<<"\n";
    for(i=0;text[i]='\0';i++){
        for(j=0;j<=i;j++)
        {
            cout<<text[j];
        }
        cout<<"\n";
    }
    return 0;
}