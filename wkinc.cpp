#include<iostream>
using namespace std;
int main(){
    float inc[7],t,avg;
    int i;
    cout<<"enter thue daily income of a person in a week:";
    for(i=0;i<=7;i++){
        cin>>inc[i];
    }
    t=0;
    for(i=0;i<=7;i++){
        t=t+inc[i];
    }
    avg=t/7;
    cout<<"the daily income of a person rs:",t;
    cout<<"the avg of a person rs:",avg;
    return 0;
}