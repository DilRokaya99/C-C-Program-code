#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    float w[7],avg,tot;
    int i;
    cout<<"enter the weekly sal of person:\n";
    for( i=1;i<7;i++){
        cin>>w[i];
        cout<<"day"<<i<<"sal:"<<w[i]<<"\n";
    }
    for(i=1;i<7;i++){
    tot+=w[i];
    }
    avg=tot/7;
    cout<<"tottal salary is:"<<tot<<"\n";
    cout<<"avg sal is:"<<avg;
    return 0;
}